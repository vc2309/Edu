# Autoboxing and Unboxing

## Array, ArrayList Recap

- Declaration

		String [] strArr = new String [10];
		//or
		ArrayList<String> strAL = new ArrayList<String>();
		strAL.add("Jim");

- Limitation : can't use primitive types in ArrayList
		
		ArrayList<int> intAL = new ArrayList<int>(); 
		//NOT allowed

## Solution : Autoboxing
- Wrap the primitive types in Wrapper Classes

		Integer integer = new Integer(54);
		ArrayList<Integer> intAL= new ArrayList<Integer>();

		for(int i=0;i<=10;i++)
		{
			intA.add(Integer.valueOf(i));
		}
- Java makes it easier

		Integer myInt = 56; //At compile time its same as
		Integer myInt = new Integer(56);