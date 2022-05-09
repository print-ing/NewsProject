#include "News.h"
#include "Reaction.h"

News::News()
{

}

News::News(string title, string text, vector<string> comments, string media, string field)
{
    news_title = title;
    news_text = text;
    news_comments = comments;
    news_categories.insert({ "��л�", media });
    news_categories.insert({ "�о�", field });
}

string News::getNewsTitle() const
{
    return news_title;
}

string News::getNewsText() const
{
    return news_text;
}

vector<string> News::getNewsComments() const
{
    return news_comments;
}

map<string, string> News::getCategory() const
{
    return news_categories; 
}

string News::getSubcategory(string category) const
{
    if (news_categories.find(category) == news_categories.end())
    {
        return "";
    }
    return news_categories.find(category)->second;
}


void News::filterSpamComment(const vector<string>& fwords)
{
    for (int i = 0; i < news_comments.size(); ++i)
    {
        for (int j = 0; j < fwords.size(); ++j)
        {
            if (news_comments[i].find(fwords[j]) != string::npos)
            {
                news_comments[i] = "���͸��Ǿ����ϴ�!!!!";
                break;
            }
        }
    }
    return;
}
// filter comment that contains fword
