import javax.swing.*;

import java.awt.*;
import java.awt.event.*;



public class Login extends Frame{
    //�����еĿؼ�
    JLabel userLa,passLa;//���� �û���������
    JTextField userTxt;//�ı��� �����û���
    JPasswordField passTxt;//����� ��������
    JButton loBt,quitBt;//��ť ��¼���˳�

    private void initControler(){//��ʼ���ؼ�����

        userLa=new JLabel("�û���");//������ǩ
        userLa.setSize(60, 30);
        userLa.setLocation(90, 50);
        this.add(userLa);//����ǩ�ŵ�������

        userTxt=new JTextField();//�����ı���
        userTxt.setSize(150, 30);
        userTxt.setLocation(160, 50);
        this.add(userTxt);//���ı���ŵ�������

        passLa=new JLabel("��   ��");//������ǩ
        passLa.setSize(60, 30);
        passLa.setLocation(90, 100);
        this.add(passLa);//����ǩ�ŵ�������

        passTxt=new JPasswordField();//���������
        passTxt.setSize(150, 30);
        passTxt.setLocation(160, 100);
        this.add(passTxt);//�������ŵ�������

        loBt=new JButton("��¼");//������ť
        loBt.setSize(60, 30);
        loBt.setLocation(120, 150);
        //loBt.addMouseListener(this);
        this.add(loBt);//����ť�ŵ�������

        quitBt=new JButton("ȡ��");//������ť
        quitBt.setSize(60, 30);
        quitBt.setLocation(210, 150);
        //quitBt.addMouseListener(this);
        this.add(quitBt);//����ť�ŵ�������
    }

    public Login(){
        this.setSize(400,250);
        this.setLocation(600,300);
        this.setTitle("������Ϣ����");
        this.setLayout(null);
        initControler();
        this.setVisible(true);//���ô���ɼ�
    }


}

class MyWindowListener implements WindowListener{//ʵ�ִ��ڼ�����

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
}


class LoginFailed extends Frame {
    JLabel information;
    JButton retry;

    private void initControler(){//��ʼ���ؼ�����

        information=new JLabel("������û�����������������������");//������ǩ
        information.setSize(300, 30);
        information.setLocation(90, 50);
        this.add(information);

    }
    public LoginFailed(){
        this.setSize(400,250);
        this.setLocation(600,300);
        this.setTitle("������Ϣ����");
        this.setLayout(null);
        initControler();
        this.setVisible(true);
    }
}

class Signin1 {
    Login signin;
    public Signin1(final Login signin){
        this.signin=signin;
        MyWindowListener mwl=new MyWindowListener();
        this.signin.addWindowListener(mwl);
        this.signin.loBt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name=signin.userTxt.getText().trim();
                //��ȡ�û���
                String pass=signin.passTxt.getText().trim();
                //��ȡ����
                String defaultUser="zuo";
                String defaultPass="123456";
                if(name.equals(defaultUser)&&pass.equals(defaultPass)){
                    //System.out.println("��¼�ɹ�");
                    //������Ҫһ������
                    signin.setVisible(false);
                    Main m=new Main();
                }else{
                    //System.out.println("��½ʧ��");
                    //������Ҫһ������
                    signin.setVisible(false);
                    LoginFailed1 lf=new LoginFailed1(new LoginFailed());
                }
            }
        });
        this.signin.quitBt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}



class LoginFailed1 {
    LoginFailed loginFailed;
    public LoginFailed1(final LoginFailed loginFailed){
        this.loginFailed=loginFailed;
        MyWindowListener mwl=new MyWindowListener();
        this.loginFailed.addWindowListener(mwl);
        this.loginFailed.retry.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	loginFailed.setVisible(false);
                Signin1 signin1=new Signin1(new Login());
            }
        });
    }
}

    





