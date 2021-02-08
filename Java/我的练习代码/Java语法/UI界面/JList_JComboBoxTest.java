import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
public class JList_JComboBoxTest implements ItemListener,ListSelectionListener{
	JList<String> list;
	JComboBox<String> comboBox;
	JFrame jframe;
	Container contentPane;
	JTextArea ta;
	JPanel jp;
	JScrollPane JS;
	GridLayout l;
	String[] item;
	JList_JComboBoxTest(){
		jframe=new JFrame("列表框与组合框测试");
		contentPane=jframe.getContentPane();
		item=new String[4];
		list=new JList<String>(item);
		JS=new JScrollPane(list);
		jp=new JPanel();
		comboBox = new JComboBox<String>();	
		ta= new JTextArea(5, 12);
		l=new GridLayout(1,2);	
		add();
		set();
		event();
	}
	void add(){
		contentPane.add(JS);
		contentPane.add(jp);
		jp.add(comboBox);
		jp.add(ta);
		comboBox.addItem("生物制药");
		comboBox.addItem("临床医学");
		comboBox.addItem("计算机科学与技术");
		comboBox.addItem("软件工程");
		item[0]="中山大学";
		item[1]="华南理工";
		item[2]="暨南大学";
		item[3]="韶关学院"; 
	}
	void set(){
		contentPane.setLayout(l);
		list.setBorder(BorderFactory.createTitledBorder("请选择学校："));
		list.setSelectedIndex(0);
		comboBox.setEditable(true);
		comboBox.setBorder(BorderFactory.createTitledBorder("请选择专业："));
		jframe.setSize(300, 200);
		jframe.setVisible(true);
	}
	void event(){
		list.addListSelectionListener(this);
		comboBox.addItemListener(this);
	}
	public static void main(String[] args) {
		new JList_JComboBoxTest();
	}
	public void itemStateChanged(ItemEvent e) {
		if(e.getSource() == comboBox)
		{
		  ta.setText( (String) comboBox.getSelectedItem() );
		}		
	}
	public void valueChanged(ListSelectionEvent e) {
		if(e.getSource() == list)
		{
		  ta.setText( (String) list.getSelectedValue() );
		}		
	}
}