# References
- We do not use explicit pointers and references in Java as we do in C++
- `House blueHouse = new House("blue")`
- this creates an object of House class called blueHouse.
- `House anotherHouse = blueHouse` points to or refers to the same object stored in blueHouse. This is a reference
- 2 references, 1 object

# Objects
- `House greenHouse = new House("green")` will create a new object with colour set to green.
- This is a new object.
- `anotherHouse = greenHouse` will set the value of anotherHouse to that of greenHouse
- To put it in C++ terms, we can say anotherHouse is now pointing at the same object pointed to by greenHouse.