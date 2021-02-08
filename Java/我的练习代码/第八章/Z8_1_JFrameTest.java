import java.awt.*;
import javax.swing.*;
public class Z8_1_JFrameTest{
	public static void main(String[] args){
		JFrame f=new JFrame();
		f.setTitle("一个简单的窗口");
		Container cp=f.getContentPane();
		cp.setLayout(new FlowLayout());
		cp.add(new JLabel("韶关学院"));
		f.setSize(250,100);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}