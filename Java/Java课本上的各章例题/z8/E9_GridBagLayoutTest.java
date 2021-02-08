package z8;
import java.awt.*;
import javax.swing.*;
public class E9_GridBagLayoutTest {
	JFrame jf;
	JButton b11;
    JButton b12;
    JButton b13;
    JPanel p14;    
    JButton b21;
    JTextArea ta22;    
    JButton b31;
    JTextField tf32;
    JButton b33; 
    E9_GridBagLayoutTest(){
    	jf=new JFrame("GridBagLayout布局演示");
        b11 = new JButton("不拉伸");
        b12 = new JButton("不拉伸");
        b13 = new JButton("不拉伸");
        p14 = new JPanel();        
        b21 = new JButton("占用2格,垂直拉伸");
        ta22 = new JTextArea("编辑框，水平和垂直拉伸");
        ta22.setBackground(Color.green);//为了看出效果，设置了颜色        
        b31 = new JButton("水平占用3格,不拉伸");
        tf32 = new JTextField("文本框，水平占用4格，水平拉伸");
        b33 = new JButton("不拉伸"); 
        GridBagLayout layout = new GridBagLayout();
        jf.setLayout(layout);
        jf.add(b11);//把组件添加进jframe
        jf.add(b12);
        jf.add(b13);
        jf.add(p14);        
        jf.add(b21);
        jf.add(ta22);        
        jf.add(b31);
        jf.add(tf32);
        jf.add(b33);       
        GridBagConstraints s= new GridBagConstraints();        
        s.fill = GridBagConstraints.BOTH; 
        //组件纵横向扩展，占满分配的空间
        s.gridwidth=1;//组件水平所占用1格
        s.weightx=0;//组件水平不拉伸
        s.weighty=0;//组件垂直不拉伸
        layout.setConstraints(b11, s);        
        layout.setConstraints(b12, s);        
        layout.setConstraints(b13, s);
        s.gridwidth=0;//为0说明该组件是该行的最后一个   
        layout.setConstraints(p14, s);  
        //---  -------完成一行设置------------------
        s.gridwidth=2;//组件水平所占用2格       
        s.weighty=1;  //组件随窗口增大进行1倍拉伸
        layout.setConstraints(b21, s);
        s.gridwidth=0;//为0说明该组件是该行的最后一个
        layout.setConstraints(ta22, s);  
        //---  -------完成一行设置------------------
        s.gridwidth=3;//组件水平所占用3格         
        s.weighty=0;  //组件垂直不拉伸
        layout.setConstraints(b31, s);
        s.gridwidth=4;//组件水平占用4格  
        s.weightx = 1;//组件随着窗口增大进行1倍拉伸
        layout.setConstraints(tf32, s);        
        s.gridwidth=0;//为0说明该组件是该行的最后一个
        s.weightx = 0;//组件水平不拉伸
        layout.setConstraints(b33, s);      
        jf.setSize(550,300);
        jf.setVisible(true);
    }
	public static void main(String[] args) {
		new E9_GridBagLayoutTest();
	}
}