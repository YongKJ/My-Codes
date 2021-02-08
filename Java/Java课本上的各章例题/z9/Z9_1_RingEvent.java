package z9;
import java.util.EventObject;
//事件类,用于封装事件源及一些与事件相关的参数
public class Z9_1_RingEvent extends EventObject{ //铃声	
	private boolean sound; //true表示上课铃声,false表示下课铃声
	public Z9_1_RingEvent(Object source,boolean sound) {
		super(source);
		this.sound = sound; 
	}	
    public void setSound(boolean sound) {
        this.sound = sound;
    }
    public boolean getSound() {
        return this.sound;
    }
}