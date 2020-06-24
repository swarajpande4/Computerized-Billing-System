#include <iostream.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <fstream.h>
#include <ctype.h>
#include <graphics.h>
#include <conio.h>

void products_enter();
void members_enter();
void readp();
void readm();
void billing();
void modifyp();
void modifym();
void deletep();
void deletem();
void instructions();

int gmode, gdriver, r;

class products_record
{
private:
	float rate;
	int stock;
	int no;
	char name[20];

public:
	void product_enter(int);
	void product_show();
	float ret_rate() { return rate; }
	int ret_stock() { return stock; }
	int ret_no() { return no; }
	char *ret_name() { return name; }
	void update_stock(int);
	void update_no(int);
	void modify();
};

products_record ob1, ob2;
fstream pro1, pro2;

class members_record
{
private:
	int no, card;
	char name[20], add[50], tel[11];
	float mem_amt;

public:
	void member_enter(int);
	void member_show();
	int ret_no() { return no; }
	int ret_card() { return card; }
	char *ret_name() { return name; }
	float ret_mem_amt() { return mem_amt; }
	void update_mem_amt(float);
	void update_no(int);
	void modify();
};

members_record m1, m2;
fstream mem1, mem2;

struct tables
{
	int no, qty;
	char name[20];
	float rate, total;
};

tables n1, n2;
int i = 0;
float discount = 0.0;

void products_record::product_enter(int x)
{
	gotoxy(28, 2);
	cprintf("ENTERING PRODUCT RECORDS ");
	gotoxy(15, 6);
	cprintf("Name :");
	gets(name);
	if (!name[0])
		return;
	gotoxy(15, 7);
	cprintf("Stock :");
	cin >> stock;
	gotoxy(15, 8);
	cprintf("Rate (Rs.):");
	cin >> rate;
	no = x;
	gotoxy(15, 9);
	cprintf("Number :");
	cout << no;
}

void products_record::update_no(int x)
{
	no = x;
}

void products_record::product_show()
{
	gotoxy(15, 7);
	cprintf("CURRENT RECORDS ARE ");
	gotoxy(15, 8);
	cprintf("PRODUCT NUMBER :");
	cout << no;
	gotoxy(15, 9);
	cprintf("NAME :");
	puts(name);
	gotoxy(15, 10);
	cprintf("RATE :(Rs.)");
	cout << rate;
	gotoxy(15, 11);
	cprintf("STOCK :");
	cprintf("%d", stock);
}

void products_record::modify()
{
	char n[20];
	int x, y;
	gotoxy(15, 13);
	cprintf("ENTER NEW PRODUCT RECORDS");
	gotoxy(15, 14);
	cprintf("NAME :");
	gets(n);
	strcpy(name, n);
	gotoxy(15, 15);
	cprintf("RATE :(Rs.)");
	cin >> x;
	rate = x;
	gotoxy(15, 16);
	cprintf("STOCK :");
	cin >> y;
	stock = y;
}

void members_record::member_enter(int x)
{
	gotoxy(28, 2);
	cprintf("ENTERING MEMBER RECORDS ");
	gotoxy(15, 6);
	cprintf("Name :");
	gets(name);
	if (!name[0])
		return;
	gotoxy(15, 7);
	cprintf("Card number :");
	cin >> card;
	gotoxy(15, 8);
	cprintf("Address :");
	gets(add);
	gotoxy(15, 9);
	cprintf("Tel. :");
	gets(tel);
	gotoxy(15, 10);
	cprintf("Membership Amount Deposited (Rs.):");
	cin >> mem_amt;
	if (mem_amt <= 100)
	{
		gotoxy(15, 11);
		cprintf("Amount less\a");
		gotoxy(15, 12);
		cprintf("Try Again");
		return;
	}
	no = x;
	gotoxy(15, 11);
	cprintf("Membership number :");
	cout << no;
}

void members_record::update_no(int x)
{
	no = x;
}

void members_record::member_show()
{
	gotoxy(15, 7);
	cprintf("CURRENT RECORDS ARE ");
	gotoxy(15, 8);
	cprintf("NAME :");
	puts(name);
	gotoxy(15, 9);
	cprintf("CARD NUMBER :");
	cout << card;
	gotoxy(15, 10);
	cprintf("ADDRESS :");
	puts(add);
	gotoxy(15, 11);
	cprintf("TELEPHONE :");
	puts(tel);
	gotoxy(15, 12);
	cprintf("MEMBERSHIP AMOUNT :(Rs.)");
	cout << mem_amt;
}

void members_record::modify()
{
	char n[20], a[50], y[12];
	int x;
	float z;
	gotoxy(15, 14);
	cprintf("ENTER NEW MEMBER RECORDS");
	gotoxy(15, 15);
	cprintf("NAME :");
	gets(n);
	strcpy(name, n);
	gotoxy(15, 16);
	cprintf("CARD NUMBER :");
	cin >> x;
	card = x;
	gotoxy(15, 17);
	cprintf("ADDRESS :");
	gets(a);
	strcpy(add, a);
	gotoxy(15, 18);
	cprintf("TELEPHONE :");
	gets(y);
	strcpy(tel, y);
	gotoxy(15, 19);
	cprintf("MEMBERSHIP AMOUNT : (Rs.)");
	cin >> z;
	mem_amt = z;
}

void members_record::update_mem_amt(float x)
{
	mem_amt = mem_amt + x;
}

void products_record::update_stock(int x)
{
	stock = stock + x;
}

void welcome()
{
	gdriver = DETECT;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	int errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		return;
	}
	setbkcolor(7);
	setcolor(15);
	settextstyle(7, HORIZ_DIR, 7);
	moveto(60, 100);
	outtext("COMPUTERIZED");
	moveto(160, 210);
	outtext("BILLING ");
	moveto(160, 320);
	outtext("SYSTEM");
	delay(1000);
	setcolor(7);
	int i = 0;
	while (i <= 2 * getmaxx() - 460)
	{
		line(0, i, i, 0);
		i++;
		delay(15);
	}
	setcolor(RED);
	sound(1450);
	delay(20);
	sound(600);
	for (r = 150; r < 230; r += 15)
	{
		circle(315, 239, r);
		sound(350 + 2 * r);
		delay(19);
		sound(1250);
	}
	settextstyle(8, HORIZ_DIR, 1);
	setcolor(LIGHTGREEN);
	sound(500);
	delay(5);
	sound(400);
	delay(23);
	moveto(220, 180);
	sound(350);
	delay(50);
	sound(100);
	outtext("SWARAJ PANDE");
	moveto(260, 200);
	sound(250);
	delay(40);
	outtext("2017-2018");
	moveto(210, 220);
	outtext("St. Thomas School");
	sound(400);
	moveto(185, 240);
	outtext("Indirapuram, GZB, UP.");
	sound(450);
	moveto(185, 260);
	delay(20);
	sound(600);
	delay(30);
	nosound();
	moveto(10, 450);
	getch();
	closegraph();
}

void border()
{
	clrscr();
	textcolor(WHITE);
	for (int i = 2; i < 80; i++)
	{
		gotoxy(i, 3);
		cprintf("-");
		gotoxy(i, 23);
		cprintf("-");
	}
	for (i = 4; i < 23; i++)
	{
		gotoxy(2, i);
		cprintf("|");
		gotoxy(79, i);
		cprintf("|");
	}
}

void main()
{
	clrscr();
	welcome();
	int n, z;
	char l = 'y';
	do
	{
		textcolor(LIGHTGREEN);
		border();
		textcolor(LIGHTGREEN);
		gotoxy(30, 5);
		cprintf("MAIN MENU");
		for (int z = 29; z <= 40; z++)
		{
			gotoxy(z, 6);
			cprintf("-");
		}
		gotoxy(20, 7);
		cprintf("1:ADD NEW PRODUCTS");
		gotoxy(20, 8);
		cprintf("2:ADD NEW MEMBERS");
		gotoxy(20, 9);
		cprintf("3:VIEW AN EXISTING PRODUCT RECORD ");
		gotoxy(20, 10);
		cprintf("4:VIEW AN EXISTING MEMBER'S RECORD ");
		gotoxy(20, 11);
		cprintf("5:PURCHASE AND FINAL BILL ");
		gotoxy(20, 12);
		cprintf("6:MODIFY PRODUCT RECORD ");
		gotoxy(20, 13);
		cprintf("7:MODIFY MEMBER'S RECORD ");
		gotoxy(20, 14);
		cprintf("8:DELETE PRODUCT RECORD ");
		gotoxy(20, 15);
		cprintf("9:DELETE MEMBER'S RECORD ");
		gotoxy(20, 16);
		cprintf("10.INSTRUCTIONS ");
		gotoxy(20, 17);
		cprintf("0.EXIT ");
		gotoxy(20, 20);
		cprintf("Enter your choice:");
		cin >> n;
		switch (n)
		{
		case 1:
			products_enter();
			break;
		case 2:
			members_enter();
			break;
		case 3:
			readp();
			break;
		case 4:
			readm();
			break;
		case 5:
			billing();
			break;
		case 6:
			modifyp();
			break;
		case 7:
			modifym();
			break;
		case 8:
			deletep();
			break;
		case 9:
			deletem();
			break;
		case 10:
			instructions();
			break;
		case 0:
			clrscr();
			textcolor(LIGHTGREEN + BLINK);
			cprintf("THANK YOU.... PRESS ANY KEY TO EXIT.");
			getch();
			l = 'n';
			break;
		default:
			gotoxy(20, 20);
			cprintf("Wrong option... Please enter again.");
			getch();
		}
	} while (l == 'y');
	clrscr();
	remove("sale.dat");
}

void products_enter()
{
	int q = 0;
	char l = 'y';
	pro1.open("products.dat", ios::in);
	pro1.seekg(0, ios::end);
	q = pro1.tellg() / sizeof(products_record);
	q += 1255;
	pro1.close();
	pro1.open("products.dat", ios::app);
	do
	{
		textcolor(LIGHTBLUE);
		clrscr();
		border();
		textcolor(LIGHTBLUE);
		ob1.product_enter(q);
		q++;
		pro1.write((char *)&ob1, sizeof(products_record));
		textcolor(LIGHTBLUE);
		gotoxy(10, 15);
		cprintf("Do you want to enter more (Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
	pro1.close();
}

products_record product_search(int no)
{
	fstream pro1;
	pro1.open("products.dat", ios::in | ios::nocreate);
	while (pro1)
	{
		pro1.read((char *)&ob1, sizeof(products_record));
		if (ob1.ret_no() == no)
			return ob1;
	}
	pro1.close();
	ob1.update_no(0);
	return ob1;
}

void modifyp()
{
	int check = 0;
	char l = 'y';
	do
	{
		textcolor(LIGHTBLUE);
		clrscr();
		border();
		textcolor(LIGHTBLUE);
		gotoxy(25, 2);
		cprintf("MODIFYING A PRODUCT RECORD");
		gotoxy(15, 5);
		cprintf("Enter the product number:");
		int no, pos;
		pos = 0;
		cin >> no;
		fstream f;
		f.open("products.dat", ios::in | ios::out);
		while (f)
		{
			pos = f.tellg();
			f.read((char *)&ob1, sizeof(products_record));
			if (f.eof())
				break;
			if (ob1.ret_no() == no)
			{
				ob1.product_show();
				ob1.modify();
				f.seekg(pos, ios::beg);
				f.write((char *)&ob1, sizeof(products_record));
				gotoxy(15, 18);
				cprintf("Record Modified.");
				check = 1;
			}
		}
		f.close();
		if (check == 0)
		{
			gotoxy(20, 9);
			cprintf("NO ENTRY\a");
		}
		gotoxy(13, 20);
		cprintf("Any more modifications desired(Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
}

void products_delete(int no)
{
	char ans = 'y';
	int check = 0;
	pro1.open("products.dat", ios::in);
	pro2.open("product1.dat", ios::app);
	pro1.seekg(0, ios::beg);

	while (pro1)
	{
		pro1.read((char *)&ob1, sizeof(products_record));
		if (pro1.eof())
			break;
		if (ob1.ret_no() == no)
		{
			check = 1;
			ob1.product_show();
			gotoxy(13, 13);
			cprintf("Do you wish to delete ?(Y/N) ");
			cin >> ans;
			if (ans == 'n' || ans == 'N')
				pro2.write((char *)&ob1, sizeof(products_record));
			else
			{
				gotoxy(13, 14);
				cprintf("Record Deleted.");
			}
		}
		else
			pro2.write((char *)&ob1, sizeof(products_record));
	}
	if (check == 0)
	{
		gotoxy(20, 9);
		cprintf("NO ENTRY\a");
	}
	pro1.close();
	pro2.close();
	remove("products.dat");
	rename("product1.dat", "products.dat");
}

void deletep()
{
	char l = 'y';
	do
	{
		textcolor(LIGHTBLUE);
		clrscr();
		border();
		textcolor(LIGHTBLUE);
		gotoxy(25, 2);
		cprintf("DELETING A PRODUCT RECORD");
		gotoxy(15, 5);
		cprintf("Enter the product number:");
		int no;
		cin >> no;
		products_delete(no);
		gotoxy(13, 20);
		cprintf("Any more deletions desired(Y/N)");
		l = getch();
	} while (tolower(l) == 'y');
}

void members_enter()
{
	int m = 0;
	char l = 'y';
	mem1.open("members.dat", ios::in);
	mem1.seekg(0, ios::end);
	m = mem1.tellg() / sizeof(members_record);
	mem1.close();
	m += 10;
	mem1.open("members.dat", ios::app);
	do
	{
		textcolor(LIGHTCYAN);
		clrscr();
		border();
		textcolor(LIGHTCYAN);
		m1.member_enter(m);
		m++;
		mem1.write((char *)&m1, sizeof(members_record));
		textcolor(LIGHTCYAN);
		gotoxy(10, 15);
	end:
		cprintf("Do you want to enter more (Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
	mem1.close();
}

members_record members_search(int no)
{
	fstream mem2;
	mem2.open("members.dat", ios::in);
	while (mem2)
	{
		mem2.read((char *)&m1, sizeof(members_record));
		if (m1.ret_no() == no)
			return m1;
	}
	mem2.close();
	m1.update_no(0);
	return m1;
}

void modifym()
{
	int check = 0;
	char l = 'y';
	do
	{
		textcolor(LIGHTBLUE);
		clrscr();
		border();
		textcolor(LIGHTBLUE);
		gotoxy(25, 2);
		cprintf("MODIFYING A MEMBER RECORD");
		gotoxy(15, 5);
		cprintf("Enter the membership number:");
		int no, pos;
		pos = 0;
		cin >> no;
		fstream f;
		f.open("members.dat", ios::in | ios::out);
		while (f)
		{
			pos = f.tellg();
			f.read((char *)&m1, sizeof(members_record));
			if (f.eof())
				break;
			if (m1.ret_no() == no)
			{
				m1.member_show();
				m1.modify();
				f.seekg(pos, ios::beg);
				f.write((char *)&m1, sizeof(members_record));
				gotoxy(15, 20);
				cprintf("Record Modified.");
				check = 1;
			}
		}
		f.close();
		if (check == 0)
		{
			gotoxy(20, 9);
			cprintf("NO ENTRY\a");
		}
		gotoxy(13, 22);
		cprintf("Any more modifications desired(Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
}

void members_delete(int no)
{
	char ans = 'y';
	int check = 0;
	mem1.open("members.dat", ios::in);
	mem2.open("member1.dat", ios::app);
	mem1.seekg(0, ios::beg);

	while (mem1)
	{
		mem1.read((char *)&m1, sizeof(members_record));
		if (mem1.eof())
			break;
		if (m1.ret_no() == no)
		{
			check = 1;
			m1.member_show();
			gotoxy(13, 13);
			cprintf("Do you wish to delete ? ");
			cin >> ans;
			if (ans == 'n' || ans == 'N')
				mem2.write((char *)&m1, sizeof(members_record));
			else
			{
				gotoxy(13, 15);
				cprintf("Record Deleted.");
			}
		}
		else
			mem2.write((char *)&m1, sizeof(members_record));
	}
	if (check == 0)
	{
		gotoxy(20, 9);
		cprintf("NO ENTRY\a");
	}
	mem1.close();
	mem2.close();
	remove("members.dat");
	rename("member1.dat", "members.dat");
}

void deletem()
{
	char l = 'y';
	do
	{
		textcolor(LIGHTCYAN);
		clrscr();
		border();
		gotoxy(25, 2);
		cprintf("DELETING MEMBER'S RECORDS ");
		gotoxy(15, 5);
		cprintf("Enter the membership number:");
		int no;
		cin >> no;
		members_delete(no);
		gotoxy(13, 22);
		cprintf("Any more deletions desired(Y/N)");
		l = getch();
	} while (tolower(l) == 'y');
}

void readp()
{
	char l = 'y';
	do
	{
		textcolor(LIGHTBLUE);
		clrscr();
		border();
		textcolor(LIGHTBLUE);
		gotoxy(28, 2);
		cprintf("VIEWING PRODUCT RECORDS");
		gotoxy(15, 6);
		cprintf("Enter product number :");
		int no;
		cin >> no;
		ob1 = product_search(no);
		if (ob1.ret_no() != 0)
			ob1.product_show();
		else
		{
			gotoxy(20, 10);
			cprintf("NO ENTRY \a");
		}
		gotoxy(15, 16);
		cprintf("Any more records desired (Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
}

void readm()
{
	char l = 'y';
	do
	{
		textcolor(LIGHTCYAN);
		clrscr();
		border();
		textcolor(LIGHTCYAN);
		gotoxy(25, 2);
		cprintf("VIEWING A MEMBER'S RECORD ");
		gotoxy(15, 6);
		cprintf("Enter membership number:");
		int no;
		cin >> no;
		m1 = members_search(no);
		if (m1.ret_no() != 0)
		{
			m1.member_show();
		}
		else
		{
			gotoxy(20, 10);
			cprintf("NO ENTRY \a");
		}
		textcolor(LIGHTCYAN);
		gotoxy(15, 16);
		cprintf("Any more records desired (Y/N) ?");
		l = getch();
	} while (tolower(l) == 'y');
}

void billing()
{
	textcolor(LIGHTRED);
	clrscr();
	border();
	textcolor(LIGHTRED);
	fstream b1;
	b1.open("sale.dat", ios::app);
	gotoxy(30, 2);
	cprintf("BILLING");
	gotoxy(15, 7);
	cprintf("Are you a member (Y/N) ?");
	float less = 1.0;
	char m;
	int no;
	int card;
	m = getche();
	if (tolower(m) == 'y')
	{
		gotoxy(18, 9);
		cprintf("Enter Membership number : ");
		cin >> no;
		gotoxy(18, 10);
		cprintf("Enter Card number : ");
		cin >> card;
		m1 = members_search(no);
		if (card != m1.ret_card())
		{
			gotoxy(20, 12);
			cprintf("Incorrect \a");
			getch();
			return;
		}
		else if (m1.ret_mem_amt() > 100)
		{
			less = 0.95;
			m1.update_mem_amt(-5);
		}
		else
		{
			gotoxy(20, 12);
			cprintf("Amount Less\a");
			gotoxy(15, 15);
			cprintf("Continue with normal billing(Y/N)");
			m = getch();
			if (tolower(m) == 'n')
				return;
		}

		fstream t3, t4;
		t3.open("members.dat", ios::in);
		t4.open("member1.dat", ios::app);
		t3.seekg(0, ios::beg);
		t3.read((char *)&m2, sizeof(members_record));
		while (!t3.eof())
		{
			if (m2.ret_no() != m1.ret_no())
				t4.write((char *)&m2, sizeof(members_record));
			else
				t4.write((char *)&m1, sizeof(members_record));
			t3.read((char *)&m2, sizeof(members_record));
		}
		t3.close();
		t4.close();
		remove("members.dat");
		rename("member1.dat", "members.dat");
	}

	clrscr();
	float total = 0.0;
	textcolor(LIGHTGREEN);
	gotoxy(60, 1);
	cprintf("p.no.= 0:Exit Billing");
	textcolor(LIGHTRED);
	gotoxy(30, 1);
	cprintf("BILLING");
	i = 0;
	void table1();
beg:
	table1();
	gotoxy(4, 6 + i);
	cin >> n1.no;
	ob1 = product_search(n1.no);
	gotoxy(56, 6 + i);
	float output1(products_record);
	if (n1.no > 0)
	{
		if (ob1.ret_no() > 0)
		{
			cin >> n1.qty;
			strcpy(n1.name, ob1.ret_name());
			n1.rate = ob1.ret_rate();
			n1.total = output1(ob1);
			total += n1.total;
			fstream t3, t4;
			t3.open("sale.dat", ios::in);
			t4.open("sale1.dat", ios::app);
			t3.seekg(0, ios::beg);
			int qty = n1.qty;
			n1.qty = n1.total / n1.rate;
			char test = 'y';
			t3.read((char *)&n2, sizeof(tables));
			while (!t3.eof())
			{
				if (n1.no == n2.no)
				{
					n2.qty += n1.qty;
					n2.total += n1.total;
					test = 'n';
				}
				t4.write((char *)&n2, sizeof(tables));
				t3.read((char *)&n2, sizeof(tables));
			}
			if (test == 'y')
			{
				t4.seekg(0, ios::end);
				t4.write((char *)&n1, sizeof(tables));
			}
			t3.close();
			t4.close();
			remove("sale.dat");
			rename("sale1.dat", "sale.dat");
			n1.qty = qty;
			if (n1.total)
			{
				fstream temp3, temp4;
				temp3.open("products.dat", ios::in);
				temp4.open("product1.dat", ios::app);
				temp3.seekg(0, ios::beg);
				temp3.read((char *)&ob1, sizeof(products_record));
				while (!temp3.eof())
				{
					if (ob1.ret_no() == n1.no)
						ob1.update_stock(-(n1.qty));
					temp4.write((char *)&ob1, sizeof(products_record));
					temp3.read((char *)&ob1, sizeof(products_record));
				}
				temp3.close();
				temp4.close();
				remove("products.dat");
				rename("product1.dat", "products.dat");
			}
			i++;
			goto beg;
		}
		else if (ob1.ret_no() == 0)
		{
			gotoxy(10, 6 + i);
			cprintf("No entry\a");
			i++;
			goto beg;
		}
	}
	else if (n1.no == 0)
	{
		textcolor(WHITE);
		for (int j = 0; j < 81; j++)
		{
			gotoxy(j, 6 + i);
			cprintf("-");
		}
	}
	textcolor(LIGHTRED);
	gotoxy(5, 9 + i);
	cprintf("Number of items = ");
	cout << i;
	gotoxy(5, 10 + i);
	cprintf("Grand total = Rs.");
	cout << total;
	if (less != 1)
	{
		discount += 0.05 * total;
		gotoxy(5, 12 + i);
		cprintf("Discount = Rs.");
		cout << 0.05 * total;
		gotoxy(5, 13 + i);
		cprintf("Net total = Rs.");
		cout << less * total;
	}
	b1.close();
	discount = 0;
	remove("sale.dat");
	getch();
}

float output1(products_record ob1)
{
	if (ob1.ret_no() == 0)
		return 0;
	float stotal;
	stotal = ob1.ret_rate() * n1.qty;
	gotoxy(4, 6 + i);
	cout << ob1.ret_no();
	gotoxy(10, 6 + i);
	puts(ob1.ret_name());
	gotoxy(38, 6 + i);
	cout << ob1.ret_rate();
	gotoxy(43, 6 + i);
	cout << "     ";
	gotoxy(56, 6 + i);
	if (n1.qty > ob1.ret_stock())
	{
		gotoxy(50, 6 + i);
		cprintf("Out of stock\a");
		return 0;
	}
	cout << n1.qty;
	gotoxy(68, 6 + i);
	cout << stotal;
	gotoxy(74, 6 + i);
	cout << "      ";
	return stotal;
}

void table1()
{
	textcolor(WHITE);
	for (int a = 1; a <= 80; a++)
	{
		gotoxy(a, 2);
		cprintf("_");
		gotoxy(a, 5);
		cprintf("-");
	}
	for (a = 3; a <= 5; a++)
	{
		gotoxy(1, a);
		cprintf("|");
		gotoxy(9, a);
		cprintf("|");
		gotoxy(31, a);
		cprintf("|");
		gotoxy(49, a);
		cprintf("|");
		gotoxy(64, a);
		cprintf("|");
		gotoxy(80, a);
		cprintf("|");
	}
	gotoxy(1, 6 + i);
	cprintf("|");
	gotoxy(9, 6 + i);
	cprintf("|");
	gotoxy(31, 6 + i);
	cprintf("|");
	gotoxy(49, 6 + i);
	cprintf("|");
	gotoxy(64, 6 + i);
	cprintf("|");
	gotoxy(80, 6 + i);
	cprintf("|");
	textcolor(LIGHTRED);
	gotoxy(2, 3);
	cprintf("Product");
	gotoxy(14, 3);
	cprintf("Product name ");
	gotoxy(35, 3);
	cprintf("Rate (Rs.)");
	gotoxy(53, 3);
	cprintf("Quantity");
	gotoxy(67, 3);
	cprintf("Total (Rs.)");
	gotoxy(2, 4);
	cprintf("Number");
	gotoxy(53, 4);
	cprintf("(Kgs/pcs)");
}

void enter()
{
	border();
	gotoxy(5, 1);
	cprintf("Entering Records");
	gotoxy(5, 7);
	textcolor(11);
	cprintf("For Products");
	textcolor(13);
	gotoxy(5, 8);
	cprintf("This part of the program helps the store management to ");
	cprintf("add more");
	gotoxy(5, 9);
	cprintf("products to their store. The existing product records are");
	cprintf(" not ");
	gotoxy(5, 10);
	cprintf("affected by this option. The new record(s) are appended at");
	cprintf(" the end");
	gotoxy(5, 11);
	cprintf("of the file containing such records namely ");
	textcolor(12);
	cprintf("'products.dat'");
	textcolor(13);
	cprintf(". This");
	gotoxy(5, 12);
	cprintf("option automatically assigns a product number to the product");
	cprintf(" which");
	gotoxy(5, 13);
	cprintf("must be remembered for any product reference.");
	gotoxy(5, 15);
	textcolor(11);
	cprintf("For members");
	textcolor(13);
	gotoxy(5, 17);
	cprintf("This option works just like its counterpart for products. It");
	cprintf(" stores");
	gotoxy(5, 18);
	cprintf("records in the file ");
	textcolor(12);
	cprintf("'members.dat'");
	textcolor(13);
	cprintf(" and assigns a membership number ");
	gotoxy(5, 19);
	cprintf("for every new entry. For further details see the help section");
	cprintf(" on ");
	textcolor(12);
	gotoxy(5, 20);
	cprintf("'Membership Rules'.");
	textcolor(13);
	getch();
}

void view()
{
	border();
	gotoxy(30, 5);
	textcolor(LIGHTBLUE);
	cprintf("Viewing Records");
	gotoxy(10, 7);
	textcolor(LIGHTRED);
	cprintf("This option enables the user to view the latest records of ");
	gotoxy(10, 8);
	cprintf("either products or members. It helps in operations like ");
	gotoxy(10, 9);
	cprintf("stock checking and member verification. The viewing is");
	gotoxy(10, 10);
	cprintf("only possible with the product/membership numbers.");
	getch();
}

void modify()
{
	border();
	gotoxy(30, 5);
	textcolor(LIGHTGREEN);
	cprintf("Modifying Records");
	gotoxy(10, 7);
	textcolor(LIGHTRED);
	cprintf("This option helps in altering the records in the files.");
	gotoxy(10, 8);
	cprintf("In case of products either the record could be changed to ");
	gotoxy(10, 9);
	cprintf("some new entry or its stock could be made zero. For members");
	gotoxy(10, 10);
	cprintf("also the same can be done but here it happens with membership");
	gotoxy(10, 11);
	cprintf("fee.");
	getch();
}

void procedure()
{
	border();
	gotoxy(10, 5);
	textcolor(LIGHTBLUE);
	cprintf("Billing and Final Bill View Procedure");
	gotoxy(10, 7);
	textcolor(LIGHTGREEN);
	cprintf("The actual billing procedure consists of two sections.");
	gotoxy(10, 8);
	cprintf("One checks if the buyer is a member or not and accordingly");
	gotoxy(10, 9);
	cprintf("performs the necessary tasks. The other section consists of ");
	gotoxy(10, 10);
	cprintf("billing. The user is asked to enter the product number and the ");
	gotoxy(10, 11);
	cprintf("quantity bought. The computer calculates the total itself and ");
	gotoxy(10, 12);
	cprintf("also the discount if necessary. In order to exit the procedure");
	gotoxy(10, 13);
	cprintf("and view the final total bill , the user should enter the product");
	gotoxy(10, 14);
	cprintf("number as '0'.");
	getch();
}

void rules()
{
	border();
	gotoxy(30, 5);
	textcolor(LIGHTGREEN);
	cprintf("Membership Rules");
	gotoxy(5, 7);
	textcolor(LIGHTBLUE);
	cprintf("The program lets its subscribers (stores) maintain a");
	cprintf(" member's list");
	gotoxy(5, 8);
	cprintf("in order to help them in increasing their sales for a");
	cprintf(" marginal cut");
	gotoxy(5, 9);
	cprintf("in their profits. The program sets minimum membership ");
	cprintf("amount as Rs.100");
	gotoxy(5, 10);
	cprintf("which must be paid at the time of registration. The member");
	cprintf(" will be ");
	gotoxy(5, 11);
	cprintf("given a membership number and a membership card (to be");
	cprintf("collected ");
	gotoxy(5, 12);
	cprintf("after a week by reference to the membership number and ");
	cprintf("other");
	gotoxy(5, 13);
	cprintf("particulars). In case a member loses the membership card ");
	cprintf(", he/she ");
	gotoxy(5, 14);
	cprintf("must register a complaint with the store by submitting a");
	cprintf(" written");
	gotoxy(5, 15);
	cprintf("application with all the particulars. He/She can collect ");
	cprintf("his/her ");
	gotoxy(5, 16);
	cprintf("remaining money by showing proofs of the particulars.");
	gotoxy(5, 17);
	textcolor(LIGHTRED);
	cprintf("The membership allows a person to avail a special discount");
	cprintf(" of 5%");
	gotoxy(5, 18);
	cprintf("over every purchase. Rs.5 will be subtracted from the ");
	cprintf("member's account");
	gotoxy(5, 19);
	cprintf("over every purchase. The account will be rendered ");
	cprintf("inaccessible if the ");
	gotoxy(5, 20);
	cprintf("amount will be less than Rs.100 and the member would be");
	cprintf(" expected to ");
	gotoxy(5, 21);
	cprintf("deposit more money for continuing the membership. The store");
	cprintf(" will also");
	gotoxy(5, 22);
	cprintf("give away attractive gifts to a lucky member once every year.");
	getch();
}

void del()
{
	border();
	gotoxy(10, 5);
	textcolor(LIGHTRED);
	cprintf("Deleting Procedure.");
	gotoxy(10, 7);
	textcolor(BLUE);
	cprintf("Deleting of Members and Products occur in two different");
	gotoxy(10, 8);
	cprintf("Programs. They ask either Membership Number or Product Number");
	gotoxy(10, 9);
	cprintf("and ask it either to delete it or not.");
	getch();
}

void instructions()
{
	clrscr();
	int n;
	char l = 'y';
	do
	{
		textcolor(13);
		border();
		textcolor(13);
		gotoxy(30, 5);
		cprintf("HELP INDEX");
		for (int z = 29; z <= 39; z++)
		{
			gotoxy(z, 6);
			cprintf("-");
		}
		gotoxy(20, 7);
		cprintf("1:ADD RECORDS");
		gotoxy(20, 8);
		cprintf("2:VIEWING RECORDS ");
		gotoxy(20, 9);
		cprintf("3:MODIFYING RECORDS");
		gotoxy(20, 10);
		cprintf("4:BILLING PROCEDURE AND FINAL BILL");
		gotoxy(20, 11);
		cprintf("5:MEMBERSHIP DETAILS");
		gotoxy(20, 12);
		cprintf("6.DELETING RECORDS");
		gotoxy(20, 13);
		cprintf("0:BACK TO MAIN MENU");
		gotoxy(21, 14);
		cprintf("Enter your choice:");
		cin >> n;
		switch (n)
		{
		case 1:
			enter();
			break;
		case 2:
			view();
			break;
		case 3:
			modify();
			break;
		case 4:
			procedure();
			break;
		case 5:
			rules();
			break;
		case 6:
			del();
			break;
		case 0:
			l = 'n';
			break;
		default:
			gotoxy(20, 16);
			cprintf("Wrong option. Please enter again.");
			getch();
		}
	} while (l == 'y');
}
