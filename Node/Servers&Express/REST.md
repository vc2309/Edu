# What is REST?

- REST ( Reprisentational State Transfer) is an architecture which provides standards for communication between computer systems.
- REST-compliant systems are called RESTful systems.

## Statelessness
- RESTful systems are stateless : they don't need to know the state of the opposite system (client doesn't need to know server state and vice versa)
- Each system is independent of the other
- There is a standard maintained for operations on resources for all RESTful systems, which eliminates the need for an interface.
- This makes RESTful systems reliable and maintains a low level of coupling allowing for high scalability.

--- 

# Procedure
- REST requires that a client makes a request to a server to
	1. retrieve
	2. send
	3. modify
	4. delete
	resources
- An HTTP request comprises of the following
	1. HTTP verb (GET/POST/PUT...) which describes the type of request
	2. HTTP header which contains info about the client and request
	3. Path to resource
	4. Optional body (which can be used to indicate parameters/keys)

---
## To be completed