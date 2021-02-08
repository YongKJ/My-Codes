package z3;
public class E11_BankCardExp {	
	public static void main(String[] args) {
		BankCard zs = new BankCard("张三","123456","6282000111001",100);		
        zs.displayMoney();
        double m=zs.drawMoney(200);
        zs.saveMoney(300);
        m=zs.drawMoney(150);
	}
}
class BankCard {
	private String name;
	private String password;   //密码
	private String cardNo;
	private double money;	
	public BankCard(String name, String password, String cardNo, double money) {
		this.name = name;
		this.password = password;
		this.cardNo = cardNo;
		this.money = money;
	}	
	public String getName() {
		return name;
	}
	public void setName(String name){ 
        this.name=name;
    }
	public String getPassword() {
		return password;
	}
	public void setPassword(String password){ 
        this.password=password;
    }	
	public String getCardNo() {
		return cardNo;
	}
	public void setCardNo(String cardNo){ 
        this.cardNo=cardNo;
    }		
	public double saveMoney(int someMoney) {
		this.money += someMoney;
		System.out.println("您刚才存入："+someMoney+" 元，账户余额还有："+money+"元");
		return money;
	}
	public double drawMoney(int someMoney) {
		if(this.money>=someMoney){
			this.money -= someMoney;
			System.out.println("您刚才取出："+someMoney+" 元，账户余额还有："+money+"元");
		}else{
			System.out.println("您的账户余额不足，无法取出："+someMoney+"元。");
		}
		return money;		
	}
	//显示余额
	public void displayMoney(){
		System.out.println("您的账户余额是："+money);	
	}
}