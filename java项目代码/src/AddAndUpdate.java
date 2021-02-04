

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class AddAndUpdate extends JFrame implements ActionListener
{
	private static final JOptionPane JOptionPanel = null;
	JLabel numLa,nameLa,contentLa,dateLa;
	JTextField numTxt,nameTxt,contentTxt,dateTxt;
	//JComboBox sexCom;
	JButton bt;
	Main main;
	public AddAndUpdate(NewsInfo news,Main main)
	{
		this.main=main;
		this.setSize(300,300);
		this.setLayout(null);
		numLa=new JLabel("���ű��");
		numLa.setSize(70, 30);
		numLa.setLocation(30, 30);
		this.add(numLa);
		nameLa=new JLabel("��������");
		nameLa.setSize(70, 30);
		nameLa.setLocation(30, 70);
		this.add(nameLa);
		contentLa=new JLabel("��������");
		contentLa.setSize(70, 30);
		contentLa.setLocation(30, 110);
		this.add(contentLa);
		dateLa=new JLabel("��������");
		dateLa.setSize(70, 30);
		dateLa.setLocation(30, 150);
		this.add(dateLa);
		
		numTxt=new JTextField();
		numTxt.setSize(120, 30);
		numTxt.setLocation(120, 30);
		this.add(numTxt);
		
		nameTxt=new JTextField();
		nameTxt.setSize(120, 30);
		nameTxt.setLocation(120, 70);
		this.add(nameTxt);
		

		contentTxt=new JTextField();
		contentTxt.setSize(120, 30);
		contentTxt.setLocation(120, 110);
		this.add(contentTxt);
		
		dateTxt=new JTextField();
		dateTxt.setSize(120, 30);
		dateTxt.setLocation(120, 150);
		this.add(dateTxt);
		
		
		bt=new JButton();
		bt.setSize(80, 30);
		bt.setLocation(80, 190);
		this.add(bt);
		
		
		if(news==null)
		{
			this.setTitle("����������Ϣ");
			bt.setText("����");
		}
		else
		{
			this.setTitle("�޸�������Ϣ");
			numTxt.setText(news.newsNum);
			numTxt.setEditable(false);
			nameTxt.setText(news.newsName);
			contentTxt.setText(news.newsContent);
			dateTxt.setText(news.newsDate);
			
			//sexCom.setSelectedItem(stu.sex);
			bt.setText("�޸�");
		}
		bt.addActionListener(this);
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		JButton bt=(JButton)e.getSource();
		NewsDAO deal=new NewsDAO();
		if(bt.getText().equals("����"))
		{
			if(numTxt.getText().trim().equals("")||nameTxt.getText().trim().equals("")||contentTxt.getText().trim().equals("")||dateTxt.getText().trim().equals(""))
            {
                JOptionPane.showMessageDialog(this, "���Բ���Ϊ��ֵ");
            }
		    else{
			String num=numTxt.getText().trim();
			String name=nameTxt.getText().trim();
			String content=contentTxt.getText().trim();
			String date=dateTxt.getText().trim();
			
			if(!checkNum(num))
			{
				JOptionPanel.showMessageDialog(this,"���ű������");
			}
			
			NewsInfo news=new NewsInfo(num,name,content,date);
			deal.addNews(news);
		   }
		}
		else
		{
			if(numTxt.getText().trim().equals("")||nameTxt.getText().trim().equals("")||contentTxt.getText().trim().equals("")||dateTxt.getText().trim().equals(""))
            {
                JOptionPane.showMessageDialog(this, "���Բ���Ϊ��ֵ");
            }
			else
			{
			String num=numTxt.getText().trim();
			String name=nameTxt.getText().trim();
			String content=contentTxt.getText().trim();
			String date=dateTxt.getText().trim();
			NewsInfo news=new NewsInfo(num,name,content,date);
			deal.updateNews(news);
			}
		}
		NewsInfo[] news=deal.findAllNews();
		main.initTable(news);
		this.dispose();//�رյ�ǰ����
	}
	
	private boolean checkNum(String num)
	{
		boolean ret=true;
		if(num.length()!=3)
		{
			ret=false;
		}
		for(int i=0;i<num.length();i++)
		{
			if(!ret)
			{
				break;
			}
			if(num.charAt(i)<'0'||num.charAt(i)>'9')
			{
				ret=false;
				break;
			}
		}
		return ret;
	}
}

