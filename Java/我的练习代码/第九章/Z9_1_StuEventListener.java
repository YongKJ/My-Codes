import java.util.EventListener;
public class Z9_1_StuEventListener implements EventListener{
    public void ListenBell(Z9_1_RingEvent e){
        if(e.getSound()){
            System.out.println("ͬѧ�ǣ��Ͽ��ˣ�");
        }else{
            System.out.println("ͬѧ�ǣ��¿��ˣ�");
        }
    }
}
