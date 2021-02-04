import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Main extends JFrame implements ActionListener{

	JTable table;//������ʾ�������ݵı��
	JScrollPane panel;//�����ű������
	NewsDAO deal=new NewsDAO();

	//��ѯ���ֿؼ�
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
        NewsDAO newsdao=new NewsDAO();//����һ��������Ԣ�����ļ��Ĳ�������
        this.setLocation(450,100);
        this.setSize(1000,800);
        this.setTitle("������Ϣ����ϵͳ");
        this.setLayout(null);
        initContorl();
        NewsInfo[] stus=newsdao.findAllNews();
        this.initTable(stus);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

	
	//ʵ�ֲ������ֿؼ��ķ�������ѯ�����ӡ�ɾ�����޸ģ�
	public void initContorl()
	{
		numLa=new JLabel("���������ű��");
		numLa.setSize(110, 30);
		numLa.setLocation(50, 20);
		this.add(numLa);
		numTxt=new JTextField();
		numTxt.setSize(170, 30);
		numTxt.setLocation(150, 20);
		this.add(numTxt);
		numBt=new JButton("��Ų�ѯ");
		numBt.setSize(110, 30);
		numBt.setLocation(330, 20);
		this.add(numBt);
		numBt.addActionListener(this);
		
		nameLa=new JLabel("��������������");
		nameLa.setSize(110, 30);
		nameLa.setLocation(50, 60);
		this.add(nameLa);
		nameTxt=new JTextField();
		nameTxt.setSize(170, 30);
		nameTxt.setLocation(150, 60);
		this.add(nameTxt);
		nameBt=new JButton("���Ʋ�ѯ");
		nameBt.setSize(110, 30);
		nameBt.setLocation(330, 60);
		this.add(nameBt);
		nameBt.addActionListener(this);

		delBt=new JButton("����");
		delBt.setSize(110, 30);
		delBt.setLocation(500, 40);
		this.add(delBt);
		delBt.addActionListener(this);
		
		addBt=new JButton("ɾ��");
		addBt.setSize(110, 30);
		addBt.setLocation(620, 40);
		this.add(addBt);
		addBt.addActionListener(this);
		
		upBt=new JButton("�޸�");
		upBt.setSize(110, 30);
		upBt.setLocation(740, 40);
		this.add(upBt);
		upBt.addActionListener(this);
		

        sBt=new JButton("ˢ��");
        sBt.setSize(110, 30);
        sBt.setLocation(860, 40);
        this.add(sBt);
        sBt.addActionListener(this);

	}
	
	public void initTable(NewsInfo[] news)//��ʼ����񷽷�
	{
		if(panel!=null)
		{
			this.remove(panel);
		}
		String[] titles={"���ű��","��������","��������","��������"};
		System.out.println(news.length);
		//���÷�������ѯ�ļ��������������������Ϣ
		String[][] values=new String[news.length][4];
		//����һ�������������ݵĶ�ά����
		for(int i=0;i<news.length;i++)
		{
			values[i][0]=news[i].newsNum;
			values[i][1]=news[i].newsName;
			values[i][2]=news[i].newsContent;
			values[i][3]=news[i].newsDate;
		}
		table=new JTable(values,titles);
		//����ֵ����ͱ����������������
		panel=new JScrollPane(table);
		panel.setSize(960, 600);
		panel.setLocation(10, 150);
		this.add(panel);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton bt=(JButton)e.getSource();
		if(bt.getText().equals("��Ų�ѯ"))
		{
			if(numTxt.getText().trim().equals(""))//�ж��Ƿ�����Ϊ��
			{
				JOptionPane.showMessageDialog(this, "���ű�Ų���Ϊ��");
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
					JOptionPane.showMessageDialog(this, "û����������");
				}
			}
		}
		else
		{
			if(bt.getText().equals("���Ʋ�ѯ"))
			{
				if(nameTxt.getText().trim().equals(""))//�ж��Ƿ�����Ϊ��
				{
					JOptionPane.showMessageDialog(this, "�������Ʋ���Ϊ��");
				}
				else
				{
					NewsInfo[] news=deal.findNewsByName(nameTxt.getText().trim());
					//System.out.println(stus.length);
					if(news==null)
					{
						JOptionPane.showMessageDialog(this, "û����������");
					}
					else
					{
						initTable(news);
					}
				}

			}
			else{
				if(bt.getText().equals("ɾ��"))
				{
					int row=table.getSelectedRow();
					//�ж��Ƿ��ڱ����ѡ��ĳһ��
					if(row==-1)//���û��ѡ���κ�һ��
					{
						JOptionPane.showMessageDialog(this, "��ѡ��Ҫɾ��������");
					}
					else
					{
						String num=table.getValueAt(row, 0).toString();
						//��ȡ��ѡ�����ű��ֵ
						
						deal.delNews(num);
						NewsInfo[] news=deal.findAllNews();
						initTable(news);
					}
				}
				else
				{
					if(bt.getText().equals("����"))
					{
						AddAndUpdate test=new AddAndUpdate(null,this);
					}
					else
					{
						if(bt.getText().equals("ˢ��"))
	                    {
	                       NewsInfo[] news=deal.findAllNews();
	                       initTable(news);
	                    }
						else
						{
							
						int row=table.getSelectedRow();
						//�ж��Ƿ��ڱ����ѡ��ĳһ��
						if(row==-1)//���û��ѡ���κ�һ��
						{
							JOptionPane.showMessageDialog(this, "��ѡ��Ҫ�޸ĵ�����");
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
