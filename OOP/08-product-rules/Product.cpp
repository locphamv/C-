#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ================= Base Class =================
class Product
{
  protected:
    static int nextId;

    int id;
    string name;
    double price;
    int quantity;

  public:
    Product();

    Product(string name, double price, int quantity);

    virtual ~Product();

    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(string name);
    void setPrice(double price);
    void setQuantity(int quantity);

    static int getNextId();

    virtual double getFinalPrice() const;

    virtual void input(istream &is);

    virtual void printInfo(ostream &os) const;

    friend istream &operator>>(istream &is, Product &p);

    friend ostream &operator<<(ostream &os, const Product &p);
};

// TODO:
// Initialize static variable nextId here
int Product::nextId = 1;
// ================= Product Implementation =================

Product::Product()
{
    // TODO:
    // assign id using nextId
    // increase nextId
    // set default name, price, quantity
    id = Product::nextId;
    Product::nextId++;
    name = "";
    price = 0;
    quantity = 0;
}

Product::Product(string name, double price, int quantity)
    : id(nextId++), name(name), price(price), quantity(quantity)
{
    // TODO:
    // assign id using nextId
    // increase nextId
    // assign name, price, quantity
}

Product::~Product()
{
    // TODO:
    // You may leave this empty
}

int Product::getId() const
{
    // TODO
    return id;
}

string Product::getName() const
{
    // TODO
    return name;
}

double Product::getPrice() const
{
    // TODO
    return price;
}

int Product::getQuantity() const
{
    // TODO
    return quantity;
}

void Product::setName(string name)
{
    // TODO
    this->name = name;
}

void Product::setPrice(double price)
{
    // TODO
    this->price = price;
}

void Product::setQuantity(int quantity)
{
    // TODO
    this->quantity = quantity;
}

int Product::getNextId()
{
    // TODO:
    // return nextId
    return nextId;
}

double Product::getFinalPrice() const
{
    // TODO:
    // Normal product has no discount and no extra fee
    // return price
    return price;
}

void Product::input(istream &is)
{
    // TODO:
    // input name, price, quantity
    // Do NOT input id
    is >> name >> price >> quantity;
}

void Product::printInfo(ostream &os) const
{
    // TODO:
    // print id, name, price, quantity, final price
    os << "ID: " << id << " | Name: " << name << " | Price: " << price
       << " | Quantity: " << quantity << " | Final Price: " << getFinalPrice();
}

istream &operator>>(istream &is, Product &p)
{
    // TODO:
    // call p.input(is)
    // return is
    p.input(is);
    return is;
}

ostream &operator<<(ostream &os, const Product &p)
{
    // TODO:
    // call p.printInfo(os)
    // return os
    p.printInfo(os);
    return os;
}

// ================= Derived Class: Book =================
class Book : public Product
{
  private:
    string author;

  public:
    Book();

    Book(string name, double price, int quantity, string author);

    double getFinalPrice() const override;

    void input(istream &is) override;

    void printInfo(ostream &os) const override;
};

// TODO: Implement Book constructors
Book::Book() : Product(), author("Unknown")
{
}

Book::Book(string name, double price, int quantity, string author)
    : Product(name, price, quantity), author(author)
{
}
double Book::getFinalPrice() const
{
    // TODO:
    // Book gets 10% discount
    return price * 0.9;
}

void Book::input(istream &is)
{
    // TODO:
    // input common product information
    // then input author
    Product::input(is);
    is >> author;
}

void Book::printInfo(ostream &os) const
{
    // TODO:
    // print product type: Book
    // print id, name, price, quantity, author, final price
    os << "Product Type: Book\n";
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Price: " << price << "\n";
    os << "Quantity: " << quantity << "\n";
    os << "Author: " << author << "\n";
    os << "Final Price: " << getFinalPrice() << "\n";
}

// ================= Derived Class: Electronic =================
class Electronic : public Product
{
  private:
    int warrantyMonths;

  public:
    Electronic();

    Electronic(string name, double price, int quantity, int warrantyMonths);

    double getFinalPrice() const override;

    void input(istream &is) override;

    void printInfo(ostream &os) const override;
};

// TODO: Implement Electronic constructors
Electronic::Electronic() : Product(), warrantyMonths(0)
{
}

Electronic::Electronic(string name, double price, int quantity, int warrantyMonths)
    : Product(name, price, quantity), warrantyMonths(warrantyMonths)
{
}

double Electronic::getFinalPrice() const
{
    // TODO:
    // Electronic has 8% service fee
    return price * 1.08;
}

void Electronic::input(istream &is)
{
    // TODO:
    // input common product information
    // then input warrantyMonths
    Product::input(is);
    is >> warrantyMonths;
}

void Electronic::printInfo(ostream &os) const
{
    // TODO:
    // print product type: Electronic
    // print id, name, price, quantity, warrantyMonths, final price
    os << "Product Type: Electronic\n";
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Price: " << price << "\n";
    os << "Quantity: " << quantity << "\n";
    os << "Warranty Months: " << warrantyMonths << "\n";
    os << "Final Price: " << getFinalPrice() << "\n";
}

// ================= Derived Class: Food =================
class Food : public Product
{
  private:
    string expiryDate;

  public:
    Food();

    Food(string name, double price, int quantity, string expiryDate);

    double getFinalPrice() const override;

    void input(istream &is) override;

    void printInfo(ostream &os) const override;
};

// TODO: Implement Food constructors
Food::Food() : Product(), expiryDate("")
{
}

Food::Food(string name, double price, int quantity, string expiryDate)
    : Product(name, price, quantity), expiryDate(expiryDate)
{
}

double Food::getFinalPrice() const
{
    // TODO:
    // If quantity >= 10, food gets 20% discount
    // Otherwise return normal price
    if (quantity >= 10)
        return price * 0.8;
    return price;
}

void Food::input(istream &is)
{
    // TODO:
    // input common product information
    // then input expiryDate
    Product::input(is);
    is >> expiryDate;
}

void Food::printInfo(ostream &os) const
{
    // TODO:
    // print product type: Food
    // print id, name, price, quantity, expiryDate, final price
    os << "Product Type: Food\n";
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Price: " << price << "\n";
    os << "Quantity: " << quantity << "\n";
    os << "Expiry Date: " << expiryDate << "\n";
    os << "Final Price: " << getFinalPrice() << "\n";
}

// ================= Order Class =================
class Order
{
  private:
    static int nextOrderId;

    int orderId;
    vector<Product *> items;

  public:
    Order();

    ~Order();

    int getOrderId() const;

    void addProduct(Product *p);

    double calculateTotal() const;

    void showOrder() const;

    static int getNextOrderId();
};

// TODO:
// Initialize static variable nextOrderId here
int Order::nextOrderId = 1000;

Order::Order()
{
    // TODO:
    // assign orderId using nextOrderId
    // increase nextOrderId
    orderId = Order::nextOrderId;
    Order::nextOrderId++;
}

Order::~Order()
{
    // TODO:
    // delete all Product* inside items
    for (Product *p : items)
        delete p;
    items.clear();
}

int Order::getOrderId() const
{
    // TODO
    return orderId;
}

void Order::addProduct(Product *p)
{
    // TODO:
    // push p into items
    items.push_back(p);
}

double Order::calculateTotal() const
{
    // TODO:
    // total = final price * quantity of each product
    double total = 0;
    for (const Product *p : items)
        total += p->getFinalPrice() * p->getQuantity();
    return total;
}

void Order::showOrder() const
{
    // TODO:
    // print orderId
    // print all products using operator <<
    // print total
    cout << "Order ID: " << orderId << "\n";
    cout << "\nProducts:\n";
    cout << "-----------------------------------\n";
    for (const Product *p : items)
        cout << *p << "\n";
    cout << "-----------------------------------\n";
    cout << "Total: " << calculateTotal() << "\n";
}

int Order::getNextOrderId()
{
    // TODO:
    // return nextOrderId
    return nextOrderId;
}

// ================= Main Function =================
int main()
{
    cout << fixed << setprecision(2);

    Order order;

    int n;
    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int choice;

        cout << "\nChoose product type:\n";
        cout << "1. Book\n";
        cout << "2. Electronic\n";
        cout << "3. Food\n";
        cout << "Your choice: ";
        cin >> choice;

        Product *p = nullptr;

        if (choice == 1)
        {
            p = new Book();
        }
        else if (choice == 2)
        {
            p = new Electronic();
        }
        else if (choice == 3)
        {
            p = new Food();
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
            i--;
            continue;
        }

        cin >> *p;

        order.addProduct(p);
    }

    cout << "\n========== ORDER SUMMARY ==========\n";
    order.showOrder();

    return 0;
}