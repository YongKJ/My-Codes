package z2;
public class E10_continueTest {	
	public static void main(String[] args) {
	loop1:for(int i=50;i<=100;i++)
		  {			
			for(int j=2;j<i;j++)
			{
				if(i%j==0)	continue loop1;
			}
			System.out.print(i+" ");
	      }
	}
}