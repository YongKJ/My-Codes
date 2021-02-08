package z10;
import java.io.*; 
public class E4_ObjetStreamTest {
	public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
		ObjectOutputStream ow=null;
		ObjectInputStream or=null; 
		ow=new ObjectOutputStream(new FileOutputStream("z10/Z10_Account.dat")); 
		or=new ObjectInputStream(new FileInputStream("z10/Z10_Account.dat"));
		ow.writeObject(new Account(100101,"张三", 3000));  
		ow.writeObject(new Account(100102,"李四", 5000)); 
		for (int i = 0; i < 2; i++) { 
			System.out.println(or.readObject());
		}
		or.close();
		ow.close(); 
	}
}
class Account implements Serializable{
	private long  number;  
    private String name;  
    private double money; 
    public Account(long number,String name, double money) {
    	super();  
        this.number=number;
        this.name = name;  
        this.money = money;  
    } 
    public String toString() {
    	String s= name+"的存折，账号="+number+"，存款="+ money;
        return s; 
    }     
}