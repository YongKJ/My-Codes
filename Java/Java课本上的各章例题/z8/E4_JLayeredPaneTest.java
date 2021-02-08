package z8;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class E4_JLayeredPaneTest implements ActionListener{	
	private JButton b1 = null, b2 = null; 
	private JLayeredPane lp = null; //分层面板	
	E4_JLayeredPaneTest() {
		JFrame f = new JFrame("JLayeredPane测试");  
		lp = f.getLayeredPane(); 
		b1 = new JButton("按钮1");
		b1.setBounds(new Rectangle(60,60,90,90)); //设计按钮的位置和大小
		b1.setVisible(true); 
		b1.addActionListener(this); 
		lp.add(b1, new Integer(20)); //将按钮1添加到指定的层		
		b2 = new JButton("按钮2"); 
		b2.setBounds(new Rectangle(120,120,90,90));
		b2.setVisible(true);
		b2.addActionListener(this);		
		lp.add(b2, new Integer(10));
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300, 300);
		f.setVisible(true);		
	}	
	public void actionPerformed(ActionEvent arg0) {
		if (arg0.getSource().equals(b1)) { //判断是哪个按钮的动作
			lp.setLayer(b1, 20); //重新设置按钮1的层数
			lp.setLayer(b2, 10);
		}else if(arg0.getSource().equals(b2)){
			lp.setLayer(b1, 10);
			lp.setLayer(b2, 20);
		}		
	}
	public static void main(String[] args) {
		new E4_JLayeredPaneTest();		
	}
}