# Encapsulation
- The mechanism which allows us to restrict the access to properties/behaviours of a class.
- Helps to seperate the user from the inner workings of a class.

## Why do we need it?
- Allowing total access to all the inner workings and properties of a class makes programs fragile and vulnerable.
- The main class should only interact with an interface of Classes, without having to access its properties directly or change its internal code.
- The main class should simply communicate with the class through function calls, and all changes which need to take place will take place within the class.

## Benefits
- "Black-box" model is achieved
- Business and functionality rules are established, and changes are only valid if they are able to pass validation within the class.
- User is unbothered with inner workings of class.
- Low coupling between classes