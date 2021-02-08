package z9;
import java.awt.event.*;
import javax.swing.*;
public class E4_MouseAdapterTest {
	JFrame f;
	JButton b1;
	E4_MouseAdapterTest(){
		f = new JFrame("鼠标适配器测试");
		b1 = new JButton("按我呀");
		f.add(b1);
		f.setSize(200, 100);		
		f.setLocationRelativeTo(null);//让窗体居中显示
		f.setVisible(true);
		b1.addMouseListener(new MouseAdapter(){
	        public void mousePressed(MouseEvent event)//鼠标按下事件
	        {
	        	b1.setText("我被Mouse按下了");
	        }});
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new E4_MouseAdapterTest();
	}
}