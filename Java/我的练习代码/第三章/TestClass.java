class Clock{
	int hour,min,sec;
	Clock(int hour,int min,int sec){
		this.hour=hour;
		this.min=min;
		this.sec=sec;
	}
	void show(){
		System.out.println("现在的时间是："+hour+"时"+min+"分"+sec+"秒");
	}
}
public class TestClass{
	public static void main(String[] args){
		Clock t=new Clock(16,32,32);
		t.show();
	}
}