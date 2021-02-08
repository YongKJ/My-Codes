import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class RadioButtonTest implements ItemListener{	
	private JFrame f;
	private JPanel cp;
	final JRadioButton schoolChild;
	final JRadioButton schoolStudent;
	final JRadioButton universityStudent;
	private JLabel sl,s2;
	private ButtonGroup group;	
    RadioButtonTest(){
    	f = new JFrame("JRadioButton测试");
        cp = new JPanel();      
        schoolChild = new JRadioButton("小学生(C)", true);
        schoolStudent = new JRadioButton("中学生(S)");
        universityStudent = new JRadioButton("大学生(U)");
        sl = new JLabel("",JLabel.CENTER);  
        s2=new JLabel("请选择：");
        group = new ButtonGroup(); //分组         
        add();
        set();
        event();
	}
	public void add(){            
        f.add(cp);
        f.add(sl);
        cp.add(s2);
        cp.add(schoolChild);
        cp.add(schoolStudent);
        cp.add(universityStudent);
        group.add(schoolChild);
        group.add(schoolStudent);
        group.add(universityStudent);
	}
	public void set(){       
        f.setLayout(new GridLayout(2, 1));
        f.setSize(300,150);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        cp.setLayout(new FlowLayout());
        schoolChild.setMnemonic(KeyEvent.VK_C);
        schoolStudent.setMnemonic(KeyEvent.VK_S);
        universityStudent.setMnemonic(KeyEvent.VK_U);
	}
	public void event(){
        schoolChild.addItemListener(this);
        schoolStudent.addItemListener(this);
        universityStudent.addItemListener(this);
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
		new RadioButtonTest();
	}
}
