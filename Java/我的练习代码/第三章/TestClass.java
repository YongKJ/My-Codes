class Clock{
	int hour,min,sec;
	Clock(int hour,int min,int sec){
		this.hour=hour;
		this.min=min;
		this.sec=sec;
	}
	void show(){
		System.out.println("���ڵ�ʱ���ǣ�"+hour+"ʱ"+min+"��"+sec+"��");
	}
}
public class TestClass{
	public static void main(String[] args){
		Clock t=new Clock(16,32,32);
		t.show();
	}
}