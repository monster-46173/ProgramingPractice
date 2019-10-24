import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Rectangle2D;

enum Colors {
    RED(Color.RED), GREEN(Color.GREEN), BLUE(Color.BLUE), BLACK(Color.BLACK), MAGENTA(Color.MAGENTA),
    CYAN(Color.CYAN), YELLOW(Color.YELLOW), PINK(Color.PINK), GRAY(Color.GRAY), ORANGE(Color.ORANGE),DARK_DRAY(Color.DARK_GRAY);

    private Color color;

    private Colors(Color c) {
        this.color = c;
    }

    public Color getColor() {
        return color;
    }

//���ȡö���е���ɫ
    public static Color getRandomColor() {
        Colors[] colors = values();
        int n = (int) (Math.random() * colors.length);
        return colors[n].color;
    }
}

class Block extends JPanel implements KeyListener {
    private int row, range, rectLength, numberToClear;
    Color[][] array;
    Color currentColor = null;

    Block() {
        this(10, 7, 70, 3);
    }

    Block(int row, int range, int rectLength, int numberToClear) {
        init(row, range, rectLength, numberToClear);
    }

    public void init(int row, int range, int rectLength, int numberToClear) {
        this.row = row;
        this.range = range;
        this.rectLength = rectLength;
        this.numberToClear = numberToClear;
        setSize(range * rectLength, (row + 1) * rectLength);
        array = new Color[row + 1][range];
        currentColor = Colors.getRandomColor();
        array[0][(range - 1) / 2] = currentColor;
        repaint();
    }

    public int getRow() { return row; }

    public int getRange() { return range; }

    public int getRectLength() { return rectLength; }

    public int getNumberToClear() { return numberToClear; }

    //���߿�
    @Override
    protected void paintBorder(Graphics g) {
        g.setColor(Color.PINK);
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3.0f));
        g2.drawLine(0, 0, getWidth() - 1, 0);
        g2.drawLine(0, 0, 0, getHeight() - 1);
        g2.drawLine(0, rectLength, getWidth() - 1, rectLength);
        g2.drawLine(getWidth() - 1, 0, getWidth() - 1, getHeight() - 1);
        g2.drawLine(0, getHeight() - 1, getWidth() - 1, getHeight() - 1);
    }
    //�����黭����
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < row + 1; i++) {
            for (int j = 0; j < range; j++) {
                Color c = array[i][j];
                if (c == null) continue;
                g.setColor(c);
                g.fillRect(j * rectLength + 1, i * rectLength + 1, rectLength - 2, rectLength - 2);
            }
        }
    }

    @Override
    public void keyTyped(KeyEvent e) { }

    @Override
    public void keyReleased(KeyEvent e) { }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        //ʵ�ּ��̡������
        if (keyCode == KeyEvent.VK_LEFT) {
            int i;
            for (i = 0; i < range; i++) {
                if (array[0][i] != null) {
                    break;
                }
            }
            if (i <= 0 || i > range - 1) {
                return;
            }
            array[0][i - 1] = array[0][i];
            array[0][i] = null;
            repaint();
        }
        //ʵ�ּ��̡������
        else if (keyCode == KeyEvent.VK_RIGHT) {
            int i;
            for (i = 0; i < range; i++) {
                if (array[0][i] != null) {
                    break;
                }
            }
            if (i >= range - 1) {
                return;
            }
            array[0][i + 1] = array[0][i];
            array[0][i] = null;
            repaint();
        }
        //ʵ�ּ��̡������
        else if (keyCode == KeyEvent.VK_DOWN) {
            int i, j = 0;
            //�ҵ���һ���еķ���
            for (i = 0; i < range; i++) {
                if (array[0][i] != null) {
                    break;
                }
            }
            //δ���ڵ�һ���ҵ�����
            if (i > range - 1) return;
            repaint();
            //������һ������ȥ
            if(array[1][i] != null) return;
            //�ҵ���ǰ��Ӧ�½�����λ��
            while (j < row && array[j + 1][i] == null) {
                j++;
            }
            //�½����̶�����Ⱦ
            Graphics g = getGraphics();
            if (g != null) {
                Graphics2D g2 = (Graphics2D) g;
                long t = System.currentTimeMillis();
                while (System.currentTimeMillis() - t < 90) {
                    Color currentColor = new Color(this.currentColor.getRed(),
                            this.currentColor.getGreen(),
                            this.currentColor.getBlue(), 10);
                    g2.setPaint(new GradientPaint(0, 0, Color.WHITE, rectLength, j * rectLength, currentColor));
                    g2.fill(new Rectangle2D.Double(i * rectLength, rectLength, rectLength, j * rectLength));
                }
            }
            //drop
            array[j][i] = array[0][i];
            array[0][i] = null;
            clear(j, i);
            //�ж����пո��Ƿ�����������������Ϸ����
            int k;
            for(k = 0; k < this.range; k++) {
                if (this.array[1][k] == null) {
                    break;
                }
            }
            //��Ϸ�����Ƿ����¿�ʼ
            if (k == this.range) {
                int a = JOptionPane.showConfirmDialog(this,
                        "��Ϸ�������Ƿ����¿�ʼ��", "Game Over!", JOptionPane.YES_NO_OPTION);
                if (a == JOptionPane.YES_OPTION) {
                    restart();
                } else {
                    System.exit(0);
                }
            }
            currentColor = Colors.getRandomColor();
            array[0][(range - 1) / 2] = currentColor;
            repaint();
        }
    }
    //���¿�ʼ
    public void restart() {
        this.array = new Color[row + 1][range];
        currentColor = Colors.getRandomColor();
        array[0][(range - 1) / 2] = currentColor;
        repaint();
    }
    //�ṩһ���հ�λ�õ����꣬���������Ķ������������棬����ṩ��λ�ò�Ϊnull�򲻽��д���
    //row��1��ʼ��range��0��ʼ
    public void drop(int row, int range) {

        if (!(row > 0 && row <= this.row && range >= 0 && range < this.range)) return;
        if (array[row][range] != null) return;
        int y = row - 1;
        while (y > 0 && array[y][range] == null) y--;
        if (y == 0) return;
        //y�������һ����������1��ʼ
        while (row <= this.row && array[row][range] == null) row++;
        row--;  //�õ���row��Ҫ�½�����λ��
        int n = 1;  //�ж��м�����������
        while (y - n > 0 && array[y - n][range] != null) n++;
        //���䵽Ҫ�½���λ��
        for (int i = row, j = y, k = 0; k < n; i--, j--, k++) {
            array[i][range] = array[j][range];
            array[j][range] = null;
            clear(i, range);
        }
    }
    //��ȥ���������ķ���
    //row��1��ʼ��range��0��ʼ
    public void clear(int row, int range) {
        boolean[][] isContinuous = new boolean[this.row][this.range];
        mark(row, range, isContinuous);
        //�ж��Ƿ�ﵽ��ȥ������������Ҫ�������������ţ�
        if (numberOfTrue(isContinuous) >= numberToClear) {
            for (int i = 1; i <= this.row; i++)
                for (int j = 0; j < this.range; j++) {
                    if (isContinuous[i - 1][j]) {
                        this.array[i][j] = null;

                        //��ȥ������Ⱦ
                        Graphics g = getGraphics();
                        if (g != null) {
                            Graphics2D g2 = (Graphics2D) g;
                            long t = System.currentTimeMillis();
                            while (System.currentTimeMillis() - t < 100) {
                                int bright = (int) (2.55 * (100 + (t - System.currentTimeMillis())));
                                System.out.println(bright);
                                g2.setColor(new Color(currentColor.getRed(), currentColor.getGreen(), currentColor.getBlue(), bright));
                                g2.fill(new Rectangle2D.Double(j * rectLength, i * rectLength, rectLength, rectLength));
                            }
                        }
                        //��ȥ��ķ���������ķ���ҲҪ�½�
                        drop(i, j);
                    }
                }
        }
    }
    //��ͬ��ɫ����һ��Ŀ���Ϊtrue�����ڴ������Ĳ���������
    //row��1��ʼ��range��0��ʼ
    public void mark(int row, int range, boolean[][] array) {
        array[row - 1][range] = true;
        Color currentColor = this.array[row][range];
        if (row > 1 && this.array[row - 1][range] == currentColor && !array[row - 2][range]) {
            mark(row - 1, range, array);
        }
        if (row < this.row && this.array[row + 1][range] == currentColor && !array[row][range]) {
            mark(row + 1, range, array);
        }
        if (range > 0 && this.array[row][range - 1] == currentColor && !array[row - 1][range - 1]) {
            mark(row, range - 1, array);
        }
        if (range < this.range - 1 && this.array[row][range + 1] == currentColor && !array[row - 1][range + 1]) {
            mark(row, range + 1, array);
        }
    }
    //ͳ��true�ĸ���
    public int numberOfTrue(boolean[][] array) {
        int n = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[0].length; j++)
                if(array[i][j]) n++;
        return n;
    }
}

class App implements ActionListener {
    JFrame myApp;
    Block myBlock;
    TextField rowTextField, rangeTextField, rectLengthTextField, numberToClearTextField;

    App() {
        myApp = new JFrame("���鱬��");
        myBlock = new Block();
        myApp.setSize(750, 1000);
        myApp.add(myBlock);
        //����˵����ܣ�Ŀǰ���������ã�
        JMenuBar mb = new JMenuBar();
        JMenu m1 = new JMenu("����");
        JMenuItem mi1 = new JMenuItem("�������");
        mi1.addActionListener(new ActionListener() {
            @Override
            //���������񵯳�������񴰿�
            public void actionPerformed(ActionEvent e) {
                JFrame setFrame = new JFrame("�������");
                setFrame.setLayout(new BorderLayout());
                Box baseBox, labelBox, textBox;
                int align = 8;//�м��
                baseBox = Box.createHorizontalBox();
                labelBox = Box.createVerticalBox();
                textBox = Box.createVerticalBox();
                //������񴰿��з�������С��С�����߳����������ȥ�������飩
                labelBox.add(new Label("row:"));
                labelBox.add(Box.createVerticalStrut(align));
                labelBox.add(new Label("range:"));
                labelBox.add(Box.createVerticalStrut(align));
                labelBox.add(new Label("rectLength:"));
                labelBox.add(Box.createVerticalStrut(align));
                labelBox.add(new Label("numberToClear:"));

                rowTextField = new TextField(String.valueOf(myBlock.getRow()));
                textBox.add(rowTextField);
                textBox.add(Box.createVerticalStrut(align));
                rangeTextField = new TextField(String.valueOf(myBlock.getRange()));
                textBox.add(rangeTextField);
                textBox.add(Box.createVerticalStrut(align));
                rectLengthTextField = new TextField(String.valueOf(myBlock.getRectLength()));
                textBox.add(rectLengthTextField);
                textBox.add(Box.createVerticalStrut(align));
                numberToClearTextField = new TextField(String.valueOf(myBlock.getNumberToClear()));
                textBox.add(numberToClearTextField);
                textBox.add(Box.createVerticalStrut(align));

                baseBox.add(labelBox);
                baseBox.add(textBox);
                setFrame.add(baseBox, BorderLayout.NORTH);

                JButton saveButton = new JButton("����");
                saveButton.addActionListener(App.this);
                setFrame.add(saveButton, BorderLayout.SOUTH);

                setFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                setFrame.pack();
                setFrame.setVisible(true);
            }
        });
        JMenuItem mi2 = new JMenuItem("���¿�ʼ");
        mi2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                myBlock.restart();
            }
        });
        JMenuItem mi3 = new JMenuItem("�˳�");
        mi3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        m1.add(mi1);
        m1.add(mi2);
        m1.add(mi3);
        mb.add(m1);
        myApp.setJMenuBar(mb);

        myApp.setLayout(null);
        myApp.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        myApp.addKeyListener(myBlock);
        myApp.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int row = Integer.parseInt(rowTextField.getText());
        int range = Integer.parseInt(rangeTextField.getText());
        int rectLength = Integer.parseInt(rectLengthTextField.getText());
        int numberToClear = Integer.parseInt(numberToClearTextField.getText());
        myBlock.removeKeyListener(myBlock);
        myBlock.init(row, range, rectLength, numberToClear);
    }

    public static void main(String[] args) {
        new App();
    }
}