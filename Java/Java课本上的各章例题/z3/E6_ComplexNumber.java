package z3;
public class E6_ComplexNumber {	
	public static void main(String[] args) {
		ComplexNumber c1 = new ComplexNumber(2.5,3.5);		
		System.out.println("C1="+c1.toString());		
		ComplexNumber c2 = new ComplexNumber(3.5,-4.5);
		System.out.println("C2="+c2.toString());		
		ComplexNumber t = c1.complexAdd(c2);
		System.out.println("C1+c2="+t.toString());
		t = c1.complexMinus(c2);
		System.out.println("C1*c2="+t.toString());
	}
}
class ComplexNumber{
	double realPart, imaginPart;
	public ComplexNumber(){
		realPart=0;
		imaginPart=0;
	}
	public ComplexNumber(double r,double i) {
		realPart=r;
		imaginPart=i;
	}
	public double getRealPart(){
		return realPart;
	}
	public double getImaginPart(){
		return imaginPart;
	}
	public ComplexNumber complexAdd(ComplexNumber c) {
		ComplexNumber tmp =new ComplexNumber();
		tmp.realPart = this.realPart + c.realPart;
		tmp.imaginPart = this.imaginPart + c.imaginPart; 
		return tmp;
	}
	public ComplexNumber complexMinus(ComplexNumber c) {
		ComplexNumber tmp =new ComplexNumber();
		tmp.realPart = this.realPart*c.realPart-this.imaginPart*c.imaginPart;
		tmp.imaginPart = this.realPart*c.imaginPart +this.imaginPart*c.realPart;
		return tmp;
	}
	public String toString(){
		if(imaginPart>=0)
			return (realPart+"+"+imaginPart+"i");
		else{
			double x=-imaginPart;
			return (realPart+"-"+x+"i");
		}
	}
}