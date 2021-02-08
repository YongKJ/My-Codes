public class Z9_1_EventTest{
    public static void main(String[] args){
        Z9_1_BellEventSource bell=new Z9_1_BellEventSource();
        bell.addStuListener(new Z9_1_StuEventListener());
        bell.RingBell(true);
        bell.RingBell(false);
    }
}
