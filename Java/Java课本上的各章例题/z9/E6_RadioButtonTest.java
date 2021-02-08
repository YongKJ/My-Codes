package z9;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class E6_RadioButtonTest implements ItemListener{	
	private JFrame f;
	private JPanel cp;
	final JRadioButton schoolChild;
	final JRadioButton schoolStudent;
	final JRadioButton universityStudent;
	private JLabel sl;	
    E6_RadioButtonTest(){
    	f = new JFrame("JRadioButton测试");       
        f.setLayout(new GridLayout(2, 1));        
        sl = new JLabel("",JLabel.CENTER);              
        schoolChild = new JRadioButton("小学生(C)", true);
        schoolStudent = new JRadioButton("中学生(S)");
        universityStudent = new JRadioButton("大学生(U)");
        schoolChild.setMnemonic(KeyEvent.VK_C);
        schoolStudent.setMnemonic(KeyEvent.VK_S);
        universityStudent.setMnemonic(KeyEvent.VK_U);
        schoolChild.addItemListener(this);
        schoolStudent.addItemListener(this);
        universityStudent.addItemListener(this);
        cp = new JPanel();
        cp.setLayout(new FlowLayout());
        cp.add(new JLabel("请选择："));
        cp.add(schoolChild);
        cp.add(schoolStudent);
        cp.add(universityStudent);      
        ButtonGroup group = new ButtonGroup(); //分组
        group.add(schoolChild);
        group.add(schoolStudent);
        group.add(universityStudent);        
        f.add(cp);
        f.add(sl);
        f.setSize(300,150);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}   	
	public void itemStateChanged(ItemEvent e) {
		JRadioButton jc = (JRadioButton) e.getSource(); 
		if (jc.isSelected()) { 			
			sl.setText(jc.getText()+" is checked");
        } else {         	
        	sl.setText(jc.getText()+" is unchecked");
        }			
	}
	public static void main(String[] args) {
		new E6_RadioButtonTest();
	}
}
