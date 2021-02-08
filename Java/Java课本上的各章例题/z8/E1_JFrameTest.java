package z8;
import java.awt.*;
import javax.swing.*;
public class E1_JFrameTest {	
	public static void main(String[] args) {
		JFrame f = new JFrame();   
        f.setTitle("一个简单窗口 ");  
        Container cp = f.getContentPane();//获得放置组件的容器对象  
        cp.setLayout(new FlowLayout());//流式布局）
        cp.add(new JLabel("韶关学院 "));
        f.setSize(250, 100); //设置窗体的大小为250*100大小   
        //f.setBounds(100,100,250,100);//指定框架在屏幕上的位置与大小
        //f.pack();       
        f.setVisible(true);   
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭  
	}
}