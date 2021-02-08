import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class MenuToolBarTest implements ActionListener,ItemListener {
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
    private JMenuBar menuBar;
    private JMenu setMenu;
    private JMenu helpMenu;
    private ImageIcon im1;
	public MenuToolBarTest() {
		f=new JFrame("菜单与工具栏测试");  
		menuBar = new JMenuBar();   
		setMenu = new JMenu("设置(S)");  
	    helpMenu = new JMenu("帮助(H)");
	    im1=new ImageIcon("z9\\z9_10_color.jpg");
	    btColor = new JButton("背景",im1);
	    im1=new ImageIcon("z9\\z9_10_Abort.jpg");
	    btAbort = new JButton("版权",im1);
	    im1=new ImageIcon("z9\\z9_10_Exit.jpg");
	    btExit = new JButton("退出",im1);
	    backColor = new JMenuItem("设置窗体背景色(C)"); 
        floatable = new JCheckBoxMenuItem("工具栏可浮动(T)"); 
        exit = new JMenuItem("退出(X)"); 
	    abort = new JMenuItem("版权...");  
	    toolBar = new JToolBar("my tool bar" );  
	    add();
	    set();
	    event();
	}
	void add(){
		cp = f.getContentPane();
	    menuBar.add(setMenu);    
	    menuBar.add(helpMenu); 
	    setMenu.add(backColor);  	      
	    setMenu.add(floatable);
	    setMenu.addSeparator();// 分隔线
	    setMenu.add(exit);
        helpMenu.add(abort);  
	    f.setJMenuBar(menuBar); 
	    //toolBar.setRollover(true); 
	    toolBar.add(btColor);
	    toolBar.add(btAbort);
	    toolBar.add(btExit);
	    cp.add(toolBar,BorderLayout.NORTH);	
	}
	void set(){
        setMenu.setMnemonic('S');
        helpMenu.setMnemonic('H');
	    btColor.setVerticalTextPosition(JButton.BOTTOM);
		btColor.setHorizontalTextPosition(JButton.CENTER);
	    btAbort.setVerticalTextPosition(JButton.BOTTOM);
		btAbort.setHorizontalTextPosition(JButton.CENTER);
	    btExit.setVerticalTextPosition(JButton.BOTTOM);
		btExit.setHorizontalTextPosition(JButton.CENTER);
        backColor.setMnemonic('C');
        floatable.setMnemonic('T');
        exit.setMnemonic('X');
        exit.setAccelerator( KeyStroke.getKeyStroke('X', java.awt.Event.CTRL_MASK, false));
	    toolBar.setFloatable(false);  
	    toolBar.addSeparator();
	    btColor.setToolTipText("设置窗体背景色");
	    btAbort.setToolTipText("版权...");
	    btExit.setToolTipText("退出");  
	    f.setSize(400, 300);  
	    f.setVisible(true); 
	    f.setDefaultCloseOperation(3);
	}
	void event(){
        backColor.addActionListener(this);
        floatable.addItemListener(this);
        exit.addActionListener(this);
        abort.addActionListener(this);
	    btColor.addActionListener(this);
	    btAbort.addActionListener(this);
	    btExit.addActionListener(this);
	}
	public static void main(String[] args) {
		new MenuToolBarTest();
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
}