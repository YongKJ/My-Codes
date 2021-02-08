package z7;
public class E5_SynchronizedTest implements Runnable {
	private static Bank bank;
	E5_SynchronizedTest(Bank bank){
		this.bank = bank; 		
	}
	public void run() {
		for (int i = 0; i < 3; i++) { 
            bank.save(100); 
        } 		
	}
	public static void main(String[] args) {
		bank = new Bank();
		E5_SynchronizedTest s=new E5_SynchronizedTest(bank);		
        Thread thread1 = new Thread(s); 
        thread1.start();        
        Thread thread2 = new Thread(s); 
        thread2.start();
	}
}
class Bank{ 
    private int money = 0;  
    public synchronized void save(int money) { //同步方法
    	int temp=this.money;
        temp+= money; 
        try {
			Thread.sleep((int) (Math.random() * 1000)); //休眠时间
		} catch (InterruptedException e) {			
			e.printStackTrace();
		}
        this.money=temp;
        String n=Thread.currentThread().getName();
        System.out.println(n + ":存入"+money+"元， 账户余额为：" + this.money); 
    } 
} 