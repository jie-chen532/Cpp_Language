import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Main extends JFrame implements ActionListener{

	JTable table;//用于显示新闻数据的表格
	JScrollPane panel;//用来放表格的面板
	NewsDAO deal=new NewsDAO();

	//查询部分控件
	JLabel numLa;
	JTextField numTxt;
	JButton numBt;
	
	JLabel nameLa;
	JTextField nameTxt;
	JButton nameBt;
	
	JButton delBt;
	JButton addBt;
	JButton upBt;
	JButton sBt;
	

    public Main()
    {
        NewsDAO newsdao=new NewsDAO();//创建一个操作公寓数据文件的操作对象
        this.setLocation(450,100);
        this.setSize(1000,800);
        this.setTitle("新闻信息管理系统");
        this.setLayout(null);
        initContorl();
        NewsInfo[] stus=newsdao.findAllNews();
        this.initTable(stus);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

	
	//实现操作部分控件的方法（查询、增加、删除、修改）
	public void initContorl()
	{
		numLa=new JLabel("请输入新闻编号");
		numLa.setSize(110, 30);
		numLa.setLocation(50, 20);
		this.add(numLa);
		numTxt=new JTextField();
		numTxt.setSize(170, 30);
		numTxt.setLocation(150, 20);
		this.add(numTxt);
		numBt=new JButton("编号查询");
		numBt.setSize(110, 30);
		numBt.setLocation(330, 20);
		this.add(numBt);
		numBt.addActionListener(this);
		
		nameLa=new JLabel("请输入新闻名称");
		nameLa.setSize(110, 30);
		nameLa.setLocation(50, 60);
		this.add(nameLa);
		nameTxt=new JTextField();
		nameTxt.setSize(170, 30);
		nameTxt.setLocation(150, 60);
		this.add(nameTxt);
		nameBt=new JButton("名称查询");
		nameBt.setSize(110, 30);
		nameBt.setLocation(330, 60);
		this.add(nameBt);
		nameBt.addActionListener(this);

		delBt=new JButton("增加");
		delBt.setSize(110, 30);
		delBt.setLocation(500, 40);
		this.add(delBt);
		delBt.addActionListener(this);
		
		addBt=new JButton("删除");
		addBt.setSize(110, 30);
		addBt.setLocation(620, 40);
		this.add(addBt);
		addBt.addActionListener(this);
		
		upBt=new JButton("修改");
		upBt.setSize(110, 30);
		upBt.setLocation(740, 40);
		this.add(upBt);
		upBt.addActionListener(this);
		

        sBt=new JButton("刷新");
        sBt.setSize(110, 30);
        sBt.setLocation(860, 40);
        this.add(sBt);
        sBt.addActionListener(this);

	}
	
	public void initTable(NewsInfo[] news)//初始化表格方法
	{
		if(panel!=null)
		{
			this.remove(panel);
		}
		String[] titles={"新闻编号","新闻名称","新闻内容","新闻日期"};
		System.out.println(news.length);
		//调用方法来查询文件中所保存的所有新闻信息
		String[][] values=new String[news.length][4];
		//创建一个用来传递数据的二维数据
		for(int i=0;i<news.length;i++)
		{
			values[i][0]=news[i].newsNum;
			values[i][1]=news[i].newsName;
			values[i][2]=news[i].newsContent;
			values[i][3]=news[i].newsDate;
		}
		table=new JTable(values,titles);
		//根据值数组和标题数组来创建表格
		panel=new JScrollPane(table);
		panel.setSize(960, 600);
		panel.setLocation(10, 150);
		this.add(panel);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton bt=(JButton)e.getSource();
		if(bt.getText().equals("编号查询"))
		{
			if(numTxt.getText().trim().equals(""))//判断是否输入为空
			{
				JOptionPane.showMessageDialog(this, "新闻编号不能为空");
			}
			else
			{
				NewsInfo newss=deal.findNewsByNum(numTxt.getText().trim());
				if(newss!=null)
				{
					NewsInfo[] news=new NewsInfo[1];
					news[0]=newss;
					initTable(news);
				}
				else
				{
					JOptionPane.showMessageDialog(this, "没有这条新闻");
				}
			}
		}
		else
		{
			if(bt.getText().equals("名称查询"))
			{
				if(nameTxt.getText().trim().equals(""))//判断是否输入为空
				{
					JOptionPane.showMessageDialog(this, "新闻名称不能为空");
				}
				else
				{
					NewsInfo[] news=deal.findNewsByName(nameTxt.getText().trim());
					//System.out.println(stus.length);
					if(news==null)
					{
						JOptionPane.showMessageDialog(this, "没有这条新闻");
					}
					else
					{
						initTable(news);
					}
				}

			}
			else{
				if(bt.getText().equals("删除"))
				{
					int row=table.getSelectedRow();
					//判断是否在表格中选中某一行
					if(row==-1)//如果没有选中任何一行
					{
						JOptionPane.showMessageDialog(this, "请选中要删除的新闻");
					}
					else
					{
						String num=table.getValueAt(row, 0).toString();
						//获取被选中新闻编号值
						
						deal.delNews(num);
						NewsInfo[] news=deal.findAllNews();
						initTable(news);
					}
				}
				else
				{
					if(bt.getText().equals("增加"))
					{
						AddAndUpdate test=new AddAndUpdate(null,this);
					}
					else
					{
						if(bt.getText().equals("刷新"))
	                    {
	                       NewsInfo[] news=deal.findAllNews();
	                       initTable(news);
	                    }
						else
						{
							
						int row=table.getSelectedRow();
						//判断是否在表格中选中某一行
						if(row==-1)//如果没有选中任何一行
						{
							JOptionPane.showMessageDialog(this, "请选中要修改的新闻");
						}
						else
						{
							String num=table.getValueAt(row, 0).toString();
						
							AddAndUpdate test=new AddAndUpdate(deal.findNewsByNum(num),this);
						}
						}
						
					}
				}
			}
		}
	}
}
