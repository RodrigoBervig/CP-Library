struct pt {
	long double x, y;

	pt(long double xx = 0.0, long double yy = 0.0) { x = xx; y = yy; }
	
	pt operator + (const pt &p) const { return pt(x + p.x, y + p.y); }
	pt operator - (const pt &p) const { return pt(x - p.x, y - p.y); }
	pt operator * (const long double c) const { return pt(x * c, y * c); } // multiplicacao por um escalar
	pt operator / (const long double c) const { return pt(x/c, y/c); }
	long double operator * (const pt &p) const { return x * p.x + y * p.y; } // produto escalar |a| * |b| * cos
	long double operator ^ (const pt &p) const { return x * p.y - y * p.x; } // produto vetorial |a| * |b| * sin
};

long double norm(pt p) { return sqrt(p * p); }
long double dist(pt p1, pt p2) { return norm(p1 - p2); }

//vectors
long double angle(pt p1, pt p2) { return acos((p1*p2)/(norm(p1) * norm(p2))); }
bool are_perpendicular(pt p1, pt p2) { return p1 * p2 == 0; } // checar problemas de precisão aqui depois
bool are_collinear(pt p1, pt p2) { return (p1 ^ p2) == 0; }
bool clockwise(pt p1, pt p2) { return (p1 ^ p2) < 0; }
bool counterclockwise(pt p1, pt p2) { return (p1 ^ p2) > 0; }

//line segments
bool segment_intersect(pt p1, pt p2, pt p3, pt p4) {
	bool condition1 = clockwise(p2-p1, p3-p1) != clockwise(p2-p1, p4-p1);
	bool condition2 = clockwise(p4-p3, p1-p3) != clockwise(p4-p3, p2-p3);
	return (condition2 && condition1);
}

bool onseg(pt a, pt b, pt c) {
	if(((b-a) ^ (c-a)) != 0) return false; //check that they are collinear first
	return (b-a) * (c-a) >= 0 && (b-a) * (c-a) <= (b-a) * (b-a); //check that the projection is in the segment and is at most the size of the segment
}

//a e b pertencem a reta R
double dist_point_line(pt a, pt b, pt p) {
	pt ab = b - a, ap = p-a;

	return abs(ab^ap)/dist(a,b);
}

//a e b são as extremidades do segmento R
double dist_point_segment(pt a, pt b, pt p) {
	pt ab = b-a, ap = p-a;
	pt ba = a-b, bp = p-b;

	//checa se o ponto p está entre duas retas perpedinculares às extremidades
	if(ab * ap < 0) { //checa se está abaixo de s
		return dist(p, a);
	}

	if(ba * bp < 0) { //checa se está acima de t
		return dist(p, b);
	}

	return dist_point_line(a, b, p);
}