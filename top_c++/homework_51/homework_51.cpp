#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str1{"�������������� ������ (������������ �������������� ������) � ������������ �������� ����������, ��������������� ������������� ������� ��� ������������� ������� ���������� ������, ���������� ����������������  � ������������ ����������."};
    std::string str2{"������� ������� � ��������, ������� ����� �������� �������� �������� ������� ����������, ��� ����������������� � �������������� �������� ������� ��������� ����������. ������, ��� �������� �������� ������������� ��� ����������� ����������."};
    std::string str3{"�������������� ������ ������ ����������� � ������, �����������, ����������, �������, ���������, �������, ��������, ��������, ���������� � ������ ��������, � ������� ��� ������� �������� ����� ���� ��������� �������������� ������, � ���������� ����� � ����������� �������."};
    
    std::string rr;
    std::string temp;

    rr.append(str3, 99, 2);
    rr.append(str1, 99, 3);
    rr.pop_back();
    rr.push_back('�');
    rr += ' ';
    rr.insert(rr.end(), str2[str2.find('�')]);
    temp.assign(str3.begin() + 87, str3.end() - 182);
    temp.replace(temp.end() - 1, temp.end(), "��");
    rr.assign(rr + temp);
    temp.clear();
    temp.assign(str2.substr(112, 16));
    temp.erase(1,4);
    temp.erase(temp.begin() + 2);
    temp.erase(temp.begin() + 3, temp.begin() + 5);
    temp.erase(4);
    rr.swap(rr += temp);
    temp.resize(0);
    rr = rr + char(static_cast<int>(false) + 32);
    rr.append(1, str2[str2.find('�') + 1]);
    rr.push_back((rr.size() < rr.max_size()) + 31);
    rr.append(str1.data() + 1, 2);
    rr.replace(rr.size() - 1, rr.size(), 1, str3.at(29));

    std::cout << rr << std::endl;
}