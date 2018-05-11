# Composition
- the relationship is called 'has-a' as opposed to an 'is-a' relationship as we saw in type Inheritance

## Example
- Consider a PC. We have the follwing components :
	1. Motherboard
	2. Monitor
	3. Case

- So we can say a PC 'has a' Motherboard, Monitor and Case.
- To translate this into Java classes, we can use the following code:

---
	public class Motherboard {
		//...
	}
	public class Monitor {
		//...
	}
	public class Case {
		//...
	}

	//Finally

	public class PC {
    private Case theCase;
    private Monitor monitor;
    private Motherboard motherboard;

    public PC(Case theCase, Monitor monitor, Motherboard motherboard) {
        this.theCase = theCase;
        this.monitor = monitor;
        this.motherboard = motherboard;
    }
    //...
	}

---



