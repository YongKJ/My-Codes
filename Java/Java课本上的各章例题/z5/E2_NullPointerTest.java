package z5;
import java.awt.Container;
import javax.swing.*;
public class E2_NullPointerTest {
    public static void main(String[] args) {
	    JFrame f = new JFrame("NullPointer异常测试");    
        Container cp = f.getContentPane();//获得容器对象  
        JLabel l = null;     
        cp.add(l); //java.lang.NullPointerException
        f.setSize(250, 100);         
        f.setVisible(true);   
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
	 }
}