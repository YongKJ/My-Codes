import java.awt.*;
import javax.swing.*;
import javax.swing.table.TableColumn;
public class JTableTest {
	JFrame f ;
	Container cp;
	JTable stu;
	TableColumn column;
	JScrollPane spane;
	final Object[] columnNames =  {"学号","姓名", "性别", "学院","专业"};
	Object[][] rowData = {
			{"201612001","张三", "男", "韶关学院", "软件工程"},
			{"201612002","李四", "女", "韶关学院", "计算机科学与技术"},
			{"201612003","王二", "男", "韶关学院", "软件外包"},
			{"201612004","黄五", "女", "韶关学院", "信息管理"},
			{"201612005","陈六", "男", "韶关学院", "通信工程"}
	};
	JTableTest(){
		f = new JFrame ("JTable测试");
	    stu = new JTable (rowData, columnNames);	
	    spane = new JScrollPane (stu);	  	    
		column=null;
	    add();
	    set();  
	}
	void add(){
		cp = f.getContentPane();
	    cp.add (spane,BorderLayout.CENTER);
	}
	void set(){
	    stu.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);//设置调整列宽的方式
	    stu.setSelectionBackground (Color.lightGray);//设置所选择行的背景色
		stu.setSelectionForeground (Color.red);      //设置所选择行的前景色
		column=stu.getColumnModel().getColumn(1); //获得表格列
		column.setPreferredWidth(30);             //设置列宽
		column=stu.getColumnModel().getColumn(2);
		column.setPreferredWidth(25);
		column=stu.getColumnModel().getColumn(4);
		column.setPreferredWidth(100);		
	    f.setSize(350,200);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new JTableTest();
	}
}