import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class JCheckBoxTest implements ItemListener{
	JFrame f = null;
	Container contentPane;
	JPanel p1;
	JCheckBox c1 = null;
	JCheckBox c2 = null;
	JCheckBox c3 = null;
	JLabel l1= null;
	String[] isSele = { "", "", "" }; 
	JCheckBoxTest(){
		f = new JFrame("JCheckBox测试");
		contentPane = f.getContentPane();
		p1 = new JPanel();
		c1 = new JCheckBox("Java程序设计");
		c2 = new JCheckBox("C#程序设计");
		c3 = new JCheckBox("设计模式");			
		l1 = new JLabel("",JLabel.CENTER); 		 
		add();
		set();
		event();			
	}
	void add(){
		p1.add(c1);
		p1.add(c2);
		p1.add(c3);	
		contentPane.add(p1);
		contentPane.add(l1);
	}	
	void set(){
		contentPane.setLayout(new GridLayout(2, 1));
		p1.setLayout(new GridLayout(1, 3));
		p1.setBorder(BorderFactory.createTitledBorder("请选择本学期的选修课："));
		f.pack();
		f.setVisible(true);   
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭 
	}
	void event(){
		c1.addItemListener(this);
		c2.addItemListener(this);
		c3.addItemListener(this);
	}
	public void itemStateChanged(ItemEvent e) {
		JCheckBox jc = (JCheckBox) e.getSource(); 
		if (jc == c1) {
			isSele[0]=jc.isSelected() ? "Java程序设计":"";
		} else if (jc == c2) {
			isSele[1]=jc.isSelected() ? "C#程序设计":"";
	    } else if (jc == c3) {
		    isSele[2]=jc.isSelected() ? "设计模式":"";
	    } 
		String sel="您的选择是："+isSele[0]+"  "+isSele[1]+"  "+isSele[2];
		l1.setText(sel);
	}
	public static void main(String[] args) {
		new JCheckBoxTest();
	}
}