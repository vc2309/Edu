# `this` vs `super`

- `this` refers to the current object.
- `super` refers to the base class properties of a derived class object.
- Neither of these can be used in a static fxn
- `this()` and `super()` can be called as references to the constructors of current object and superclass object.

# Constructor example
	//for class Shape
	public Shape(int x,int y)
	{
		this.x = x;
		this.y = y;
	}

	//for class Rectangle which extends Shape
	public Rectangle(){
		this(0,0);
	}
	public Rectangle(int width,int height){
		this(0,0,width,height);
	}
	public Rectangle(int x, int y, int w, int h){
		super(x,y);
		this.width=w;
		this.height=h;
	}


# `static`
- Same as C++