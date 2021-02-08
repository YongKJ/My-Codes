import java.util.EventObject;
public class Z9_1_RingEvent extends EventObject{
    private boolean sound;
    public Z9_1_RingEvent(Object source,boolean sound){
        super(source);
        this.sound=sound;
    }
    public void setSound(boolean sound){
        this.sound=sound;
    }
    public boolean getSound(){
        return this.sound;
    }
}
