#include "UserInteraction.h"

void UserInteraction::receiveUserReaction(Reaction& reaction)
{
    string index_str;
    cout << "���������� �����ϽŴٸ� [1]" << "\t" << "���������� �����ϽŴٸ� [2]" << endl;
    cout << "�����ϰ� ���� �����ôٸ� �ٸ� ���ڸ� �Է����ּ���. " << endl;
    while (1)
    {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            switch (index) {
            case 1:
                reaction.PlusPositive();
                cout << "�������� ������ �Է��ϼ̽��ϴ�." << endl;
                break;
            case 2:
                reaction.PlusNegative();
                cout << "�������� ������ �Է��ϼ̽��ϴ�." << endl;
                break;
            default:
                cout << "������ �Է����� �����̽��ϴ�." << endl;
            }
            cout << "------------------------------------------------------------------------------------------" << endl;
            return;
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�!!!!" << endl;
        }
    }
}

vector<Subcategory>& UserInteraction::selectMainCategory(vector<MainCategory>& main_category, Display display)
{
    vector<Subcategory> empty_subcategories;
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "��� �з� ������ �׸��μ̽��ϴ�." << endl;
                return empty_subcategories;
            }
            else if (index >= main_category.size()) 
            {
                cout << "�߸��� �Է��Դϴ�!!!!" << endl;
            }
            else 
            {
                display.printSelect(main_category[index].getMainCategoryName());
                return main_category[index].getSubcategories();
            }
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�!!!!" << endl;
        }
    }
}

Subcategory& UserInteraction::SingleSubCategory(vector<Subcategory>& sub_category, Display display)
{
    Subcategory empty_subcategory;
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "��� �з� ������ �׸��μ̽��ϴ�." << endl;
                return empty_subcategory;
            }
            else if (index >= sub_category.size()) {
                cout << "�߸��� �Է��Դϴ�!!!!" << endl;
            }
            else {
                display.printSelect(sub_category[index].getSubcategoryName());
                return sub_category[index];
            }
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�!!!!" << endl;
        }
    }
}

/*
vector<News*> UserInteraction::selectSubCategory(vector<Subcategory> sub_category, Display display)
{
    cout << "�����ϰ� �����ôٸ� -1�� �Է����ּ���!" << endl;
    vector<News*> select_news;
    int index;
    while (1) {
        cin >> index;

        if (index == -1)
        {
            cout << "��� �з� ������ �׸��μ̽��ϴ�." << endl;
            return select_news;
        }
        else if (index >= sub_category.size()) {
            cout << "�߸��� �Է��Դϴ�!!!!" << endl;
        }

        else {
            display.printSelect(sub_category[index].getSubcategoryName());
            return sub_category[index].getSubcategoryNews();
        }
    }
}
*/

News* UserInteraction::selectNews(const vector<News*>& selected_news)
{
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "��� ������ �׸��μ̽��ϴ�." << endl;
                return NULL;
            }
            else if (index >= selected_news.size()) {
                cout << "�߸��� �Է��Դϴ�!!!!" << endl;
            }

            else 
            {
                cout << "[" << index << "]" << "�� ������ �����ϼ̽��ϴ�!" << endl;
                return selected_news[index];
            }
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�!!!!" << endl;
        }
    }
}

bool UserInteraction::isIntegerInput(string input)
{
    bool is_integer = 0;
    if (input.size() >= 10)
    {
        return 0;
    }
    for (int i = 0; i < input.size(); ++i)
    {
        if ('0' <= input[i] && '9' >= input[i])
        {
            is_integer = 1;
            break;
        }
    }
    return is_integer;
}