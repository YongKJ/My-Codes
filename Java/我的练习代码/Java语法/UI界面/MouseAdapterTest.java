import java.awt.event.*;
import javax.swing.*;
public class MouseAdapterTest {
	JFrame f;
	JButton b1;
	MouseAdapterTest(){
		f = new JFrame("鼠标适配器测试");
		b1 = new JButton("按我呀");
		add();
		set();
		event();
	}
	void add(){
		f.add(b1);
	}
	void set(){
		f.setSize(200, 100);		
		f.setLocationRelativeTo(null);//让窗体居中显示
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	void event(){
		b1.addMouseListener(new MouseAdapter(){
	        public void mousePressed(MouseEvent event)//鼠标按下事件
	        {
	        	b1.setText("我被Mouse按下了");
	        }
	    });
	}
	public static void main(String[] args) {
		new MouseAdapterTest();
	}
}