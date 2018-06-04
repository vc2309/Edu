#Reference vs Value Types
- Copying by value means creating a new independent variable, with the same value held
- Copy by Reference means the same address is held by both variables.

## Reference types
- To make a reference array, we do the following 

		int [] myArr = new int [5];
		int [] refArr = myArr;
- Now refArr and myArr are referencing the same addresses in memory. 