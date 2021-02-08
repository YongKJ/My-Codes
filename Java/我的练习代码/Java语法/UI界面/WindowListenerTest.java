import java.awt.event.*;
import javax.swing.*;
public class WindowListenerTest{
	JFrame f;
	JLabel l;
	WinEvent inClass;
	WindowListenerTest(){
		f = new JFrame("WindowEvent测试");
		l=new JLabel("显示当前窗口的状态",JLabel.CENTER); 
		inClass=new WinEvent();
		add();
		set();
	}
	void add(){
		f.add("Center",l);
		f.addWindowListener(inClass);
	}
	void set(){
		f.setSize(300, 200);
		f.setVisible(true);
		f.setLocationRelativeTo(null);  //让窗体居中显示
	}
	public static void main(String[] args) {
		new WindowListenerTest();
	}
	public class WinEvent implements WindowListener{
		public void windowOpened(WindowEvent e) {
			l.setText("窗口当前状态：windowOpened");
		}
		public void windowActivated(WindowEvent e) {
			l.setText("窗口当前状态：windowActivated");
		}
		public void windowDeactivated(WindowEvent e) {
			l.setText("窗口当前状态：windowDeactivated");
		}
		public void windowIconified(WindowEvent e) {
			System.out.println("窗口当前状态：windowIconified");
		}
		public void windowDeiconified(WindowEvent e) {
			System.out.println("窗口当前状态：windowDeiconified");
		}
		public void windowClosing(WindowEvent e)// 单击框架上的关闭按钮事件
		{
			System.out.println("窗口当前状态：windowClosing");
			System.exit(0);		
		}
		public void windowClosed(WindowEvent e) {
			System.out.println("窗口当前状态：windowClosed");	
		}		
	}
}
