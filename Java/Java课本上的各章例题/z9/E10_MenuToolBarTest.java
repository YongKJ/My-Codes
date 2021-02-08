//package z9;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class E10_MenuToolBarTest implements ActionListener,ItemListener {
	private JFrame f;
	private Container cp;
	private JMenuItem backColor;
	private JCheckBoxMenuItem floatable;
	private JMenuItem exit;
	private JMenuItem abort;
	private JToolBar toolBar;
	private JButton btColor;
    private JButton btAbort;
    private JButton btExit; 
	public E10_MenuToolBarTest() {
		f=new JFrame("菜单与工具栏测试");  
		cp = f.getContentPane();
		JMenuBar menuBar = new JMenuBar();   
		JMenu setMenu = new JMenu("设置(S)");  
	    JMenu helpMenu = new JMenu("帮助(H)");
        setMenu.setMnemonic('S');
        helpMenu.setMnemonic('H');
	    menuBar.add(setMenu);    
	    menuBar.add(helpMenu); 
	    ImageIcon im1=new ImageIcon("z9\\z9_10_color.jpg");
	    btColor = new JButton("背景",im1);
	    btColor.setVerticalTextPosition(JButton.BOTTOM);
		btColor.setHorizontalTextPosition(JButton.CENTER);
	    im1=new ImageIcon("z9\\z9_10_Abort.jpg");
	    btAbort = new JButton("版权",im1);
	    btAbort.setVerticalTextPosition(JButton.BOTTOM);
		btAbort.setHorizontalTextPosition(JButton.CENTER);
	    im1=new ImageIcon("z9\\z9_10_Exit.jpg");
	    btExit = new JButton("退出",im1);
	    btExit.setVerticalTextPosition(JButton.BOTTOM);
		btExit.setHorizontalTextPosition(JButton.CENTER);
	    backColor = new JMenuItem("设置窗体背景色(C)"); 
        floatable = new JCheckBoxMenuItem("工具栏可浮动(T)"); 
        exit = new JMenuItem("退出(X)"); 
        backColor.setMnemonic('C');
        floatable.setMnemonic('T');
        exit.setMnemonic('X');
        exit.setAccelerator( KeyStroke.getKeyStroke('X', java.awt.Event.CTRL_MASK, false));
        backColor.addActionListener(this);
        floatable.addItemListener(this);
        exit.addActionListener(this);
	    setMenu.add(backColor);  	      
	    setMenu.add(floatable);
	    setMenu.addSeparator();// 分隔线
	    setMenu.add(exit);
	    abort = new JMenuItem("版权...");
        helpMenu.add(abort);  
        abort.addActionListener(this);
	    f.setJMenuBar(menuBar);     
	    toolBar = new JToolBar("my tool bar" );
	    toolBar.setFloatable(false);
	    //toolBar.setRollover(true); 
	    toolBar.add(btColor);
	    toolBar.add(btAbort);
	    toolBar.addSeparator();
	    toolBar.add(btExit);
	    btColor.setToolTipText("设置窗体背景色");
	    btAbort.setToolTipText("版权...");
	    btExit.setToolTipText("退出");
	    btColor.addActionListener(this);
	    btAbort.addActionListener(this);
	    btExit.addActionListener(this);
	    cp.add(toolBar,BorderLayout.NORTH);	    
	    f.setSize(400, 300);  
	    f.setVisible(true); 
	    f.setDefaultCloseOperation(3);
	}
	public void actionPerformed(ActionEvent e) {
		String sourceName = e.getActionCommand();
		if(sourceName.equals("设置窗体背景色(C)")||sourceName.equals("背景")){
			Color newColor =JColorChooser.showDialog(f, "选择背景颜色",cp.getBackground()); 
			cp.setBackground(newColor);				
		}else if(sourceName.equals("版权...")||sourceName.equals("版权")) {
			JOptionPane.showMessageDialog(f, "本软件由婺江笠翁设计。", "关于本软件", JOptionPane.INFORMATION_MESSAGE);						
	    }else if(sourceName.equals("退出(X)")||sourceName.equals("退出")) {
			System.exit(1);			
	    }
	}
	public void itemStateChanged(ItemEvent e) {
		JCheckBoxMenuItem fa = (JCheckBoxMenuItem) e.getSource(); 
		if (fa.isSelected()) {			
			toolBar.setFloatable(true);		
		} else {
			toolBar.setFloatable(false);
		}
	}
	public static void main(String[] args) {
		new E10_MenuToolBarTest();
	}	
}