import java.util.EventListener;
public class Z9_1_StuEventListener implements EventListener{
    public void ListenBell(Z9_1_RingEvent e){
        if(e.getSound()){
            System.out.println("同学们，上课了！");
        }else{
            System.out.println("同学们，下课了！");
        }
    }
}
