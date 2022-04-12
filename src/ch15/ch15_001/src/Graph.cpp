#include "../include/Graph.h"
#include <map>

namespace Graph_lib {

void Shape::draw_lines() const
{
	if (color().visibility() && 1<points.size())	// draw sole pixel?
		for (unsigned int i=1; i<points.size(); ++i)
			fl_line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
}

void Shape::draw() const
{
	Fl_Color oldc = fl_color();
	// there is no good portable way of retrieving the current style
	fl_color(lcolor.as_int());
	fl_line_style(ls.style(),ls.width());
	draw_lines();
	fl_color(oldc);	// reset color (to pevious) and style (to default)
	fl_line_style(0);
}

void Binary_tree::draw_lines() const
{
	if (color().visibility()) {
		fl_color(color().as_int());

		//
		// fl_arc(100,100,20,20,0,360);
		// fl_draw("_level-0",100,100);
		// //
		// Arrow a({110,120},{60,150});
		// a.draw_lines();
		// Arrow b({110,120},{160,150});
		// b.draw_lines();
		// //
		// fl_arc(50,150,20,20,0,360);
		// fl_draw("_level-1",50,150);
		// fl_arc(150,150,20,20,0,360);
		// fl_draw("_level-1",150,150);
		//
		Circle a({100,100},10);
		Circle a1({50,150},10);
		Circle a2({150,150},10);
		Arrow toa1({100,110},{50,140});
		Arrow toa2({100,110},{150,140});

		a.draw_lines();
		a1.draw_lines();
		a2.draw_lines();
		toa1.draw_lines();
		toa2.draw_lines();
	}
	
}

// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
{
    double x1 = p1.x;
    double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;

	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom == 0){
		parallel= true;
		return pair<double,double>(0,0);
	}
	parallel = false;
	return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
								((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}


//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
} 

void Polygon::add(Point p)
{
	int np = number_of_points();

	if (1<np) {	// check that thenew line isn't parallel to the previous one
		if (p==point(np-1)) error("polygon point equal to previous point");
		bool parallel;
		line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
		if (parallel)
			error("two polygon points lie in a straight line");
	}

	for (int i = 1; i<np-1; ++i) {	// check that new segment doesn't interset and old point
		Point ignore(0,0);
		if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
			error("intersect in polygon");
	}
	

	Closed_polyline::add(p);
}


void Polygon::draw_lines() const
{
		if (number_of_points() < 3) error("less than 3 points in a Polygon");
		Closed_polyline::draw_lines();
}

void Open_polyline::draw_lines() const
{
		if (fill_color().visibility()) {
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			for(int i=0; i<number_of_points(); ++i){
				fl_vertex(point(i).x, point(i).y);
			}
			fl_end_complex_polygon();
			fl_color(color().as_int());	// reset color
		}
		
		if (color().visibility())
			Shape::draw_lines();
}


void Closed_polyline::draw_lines() const
{
	Open_polyline::draw_lines();
		
	if (color().visibility())	// draw closing line:
		fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,point(0).x,point(0).y);
}

void Octagon::draw_lines() const
{
	// +/-1,+/-(1+sqrt(2))
	// +/-(1+sqrt(2)), +/-1
	// fl_line(point(0).x,point(0).y,point(0).x,point(0).y+r);
	// draw_mark(point(0),'+');

	// draw_mark({point(0).x+r, point(0).y},'+');
	// draw_mark({point(0).x+r, point(0).y*0.924},'1');
	// draw_mark({point(0).x+r, point(0).y/0.924},'2');

	// draw_mark({point(0).x-r, point(0).y},'+');
	// draw_mark({point(0).x-r, point(0).y*0.924},'3');
	// draw_mark({point(0).x-r, point(0).y/0.924},'4');
	
	// draw_mark({point(0).x, point(0).y+r},'+');
	// draw_mark({point(0).x*0.924,point(0).y+r},'5');
	// draw_mark({point(0).x/0.924,point(0).y+r},'6');

	// draw_mark({point(0).x,point(0).y-r},'+');
	// draw_mark({point(0).x*0.924,point(0).y-r},'7');
	// draw_mark({point(0).x/0.924,point(0).y-r},'8');

	double d= cos(22.5*M_PI/180);

	// cout << __PRETTY_FUNCTION__ << endl;
	
	fl_line(point(0).x+r, point(0).y/d, point(0).x+r, point(0).y*d);
	fl_line(point(0).x+r, point(0).y*d, point(0).x/d,point(0).y-r);
	fl_line(point(0).x/d,point(0).y-r, point(0).x*d,point(0).y-r);
	fl_line(point(0).x*d,point(0).y-r, point(0).x-r, point(0).y*d);
	fl_line(point(0).x-r, point(0).y*d,point(0).x-r, point(0).y/d);
	fl_line(point(0).x-r, point(0).y/d, point(0).x*d,point(0).y+r);
	fl_line(point(0).x*d,point(0).y+r, point(0).x/d,point(0).y+r);
	fl_line(point(0).x/d,point(0).y+r, point(0).x+r, point(0).y/d);
}

void Shape::move(int dx, int dy)
{
	for (unsigned int i = 0; i<points.size(); ++i) {
		points[i].x+=dx;
		points[i].y+=dy;
	}
}

void Lines::draw_lines() const
{
//	if (number_of_points()%2==1) error("odd number of points in set of lines");
	if (color().visibility())
		for (int i=1; i<number_of_points(); i+=2)
			fl_line(point(i-1).x,point(i-1).y,point(i).x,point(i).y);
}

void Text::draw_lines() const
{
	int ofnt = fl_font();
	int osz = fl_size();
	fl_font(fnt.as_int(),fnt_sz);
	fl_draw(lab.c_str(), point(0).x, point(0).y);
	fl_font(ofnt,osz);
}

Function::Function(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
	if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

void Rectangle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_rectf(point(0).x,point(0).y,w,h);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w,h);
	}
}


Axis::Axis(Orientation d, Point xy, int length, int n, string lab)
	:label(Point(0,0),lab)
{
	if (length<0) error("bad axis length");
	switch (d){
	case Axis::x:
		{	Shape::add(xy);	// axis line
			Shape::add(Point(xy.x+length,xy.y));	// axis line
			if (1<n) {
				int dist = length/n;
				int x = xy.x+dist;
				for (int i = 0; i<n; ++i) {
					notches.add(Point(x,xy.y),Point(x,xy.y-5));
				x += dist;
			}
		}
		// label under the line
		label.move(length/3,xy.y+20);
		break;
	}
	case Axis::y:
		{	Shape::add(xy);	// a y-axis goes up
			Shape::add(Point(xy.x,xy.y-length));
			if (1<n) {
			int dist = length/n;
			int y = xy.y-dist;
			for (int i = 0; i<n; ++i) {
				notches.add(Point(xy.x,y),Point(xy.x+5,y));
				y -= dist;
			}
		}
		// label at top
		label.move(xy.x-10,xy.y-length-10);
		break;
	}
	case Axis::z:
		error("z axis not implemented");
	}
}

void Axis::draw_lines() const
{
	Shape::draw_lines();	// the line
	notches.draw();	// the notches may have a different color from the line
	label.draw();	// the label may have a different color from the line
}


void Axis::set_color(Color c)
{
	Shape::set_color(c);
	notches.set_color(c);
	label.set_color(c);
}

void Axis::move(int dx, int dy)
{
	Shape::move(dx,dy);
	notches.move(dx,dy);
	label.move(dx,dy);
}

void Circle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}

void Smiley::draw_lines() const
{
	if(color().visibility())
	{
		Circle::draw_lines();
		fl_color(color().as_int());
		fl_arc(point(0).x+radius()/2,point(0).y+radius()/2,radius()/4,radius()/4,0,360);
		fl_arc(point(0).x+1.25*radius(),point(0).y+radius()/2,radius()/4,radius()/4,0,360);
		fl_arc(center().x-radius()/4,center().y,radius()/2,radius()/2,180,360);
	}

}

void Smileyh::draw_lines() const
{
	if(color().visibility())
	{
		Smiley::draw_lines();
		fl_color(color().as_int());
		fl_line(point(0).x, point(0).y, point(0).x+2*radius(), point(0).y);
	}
}

void Frowney::draw_lines() const
{
	if(color().visibility())
	{
		Circle::draw_lines();
		fl_color(color().as_int());
		fl_arc(point(0).x+radius()/2,point(0).y+radius()/2,radius()/4,radius()/4,0,360);
		fl_arc(point(0).x+1.25*radius(),point(0).y+radius()/2,radius()/4,radius()/4,0,360);
		fl_arc(center().x-radius()/4,center().y,radius()/2,radius()/2,0,180);
	}

}


void Ellipse::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,0,360);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,0,360);
	}
}

void Arc::draw_lines() const
{
	if(fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1, h+h-1, init, end);
		fl_color(color().as_int());
	}

	if(color().visibility()) {	
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w+w, h+h, init, end);
	}
}

void Box::draw_lines() const
{
	if(color().visibility())
	{
		fl_draw_box(Fl_Boxtype::_FL_ROUNDED_BOX,point(0).x, point(0).y,w,h,color().as_int());
	}
}

void Arrow::draw_lines() const
{
	Line::draw_lines();

	double norm=0, udx=0, udy=0, dx=0, dy=0;
	double ax, bx, ay, by;

	dx=(double)point(1).x-point(0).x;
	dy=(double)point(1).y-point(0).y;

	norm = sqrt(pow(dx,2)+pow(dy,2));

	udx= dx/norm;
	udy= dy/norm;

	ax = udx * sqrt(3)/2 - udy * 1/2;
	ay = udx * 1/2 + udy * sqrt(3)/2;
	bx = udx * sqrt(3)/2 + udy * 1/2;
	by = -udx * 1/2 + udy * sqrt(3)/2;

	fl_line(point(1).x,point(1).y, point(1).x-10*ax, point(1).y-10*ay);
	fl_line(point(1).x,point(1).y, point(1).x-10*bx, point(1).y-10*by);
}

void draw_mark(Point xy, char c)
{
	static const int dx = 4;
	static const int dy = 4;
	string m(1,c);
	fl_draw(m.c_str(),xy.x-dx,xy.y+dy);
}

void Marked_polyline::draw_lines() const
{
	Open_polyline::draw_lines();
	for (int i=0; i<number_of_points(); ++i) 
		draw_mark(point(i),mark[i%mark.size()]);
}
/*
void Marks::draw_lines() const
{
	for (int i=0; i<number_of_points(); ++i) 
		fl_draw(mark.c_str(),point(i).x-4,point(i).y+4);
}
*/


std::map<string,Suffix::Encoding> suffix_map;

int init_suffix_map()
{
	suffix_map["jpg"] = Suffix::jpg;
	suffix_map["JPG"] = Suffix::jpg;
	suffix_map["jpeg"] = Suffix::jpg;
	suffix_map["JPEG"] = Suffix::jpg;
	suffix_map["gif"] = Suffix::gif;
	suffix_map["GIF"] = Suffix::gif;
	suffix_map["bmp"] = Suffix::bmp;
	suffix_map["BMP"] = Suffix::bmp;
	return 0;
}

Suffix::Encoding get_encoding(const string& s)
		// try to deduce type from file name using a lookup table
{
	static int x = init_suffix_map();

	string::const_iterator p = find(s.begin(),s.end(),'.');
	if (p==s.end()) return Suffix::none;	// no suffix

	string suf(p+1,s.end());
	return suffix_map[suf];
}

bool can_open(const string& s)
            // check if a file named s exists and can be opened for reading
{
	ifstream ff(s.c_str());
	return bool(ff);
}


// somewhat overelaborate constructor
// because errors related to image files can be such a pain to debug
Image::Image(Point xy, string s, Suffix::Encoding e)
	:w(0), h(0), fn(xy,"")
{
	add(xy);

	if (!can_open(s)) {
		fn.set_label("cannot open \""+s+'\"');
		p = new Bad_image(30,20);	// the "error image"
		return;
	}

	if (e == Suffix::none) e = get_encoding(s);
	
	switch(e) {
	case Suffix::jpg:
		p = new Fl_JPEG_Image(s.c_str());
		break;
	case Suffix::gif:
		p = new Fl_GIF_Image(s.c_str());
		break;
//	case Suffix::bmp:
//		p = new Fl_BMP_Image(s.c_str());
//		break;
	default:	// Unsupported image encoding
		fn.set_label("unsupported file type \""+s+'\"');
		p = new Bad_image(30,20);	// the "error image"
	}
}

void Image::draw_lines() const
{
	if (fn.label()!="") fn.draw_lines();

	if (w&&h)
		p->draw(point(0).x,point(0).y,w,h,cx,cy);
	else
		p->draw(point(0).x,point(0).y);
}

} // Graph