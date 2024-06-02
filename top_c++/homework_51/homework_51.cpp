#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str1{"Математический анализ (классический математический анализ) — совокупность разделов математики, соответствующих историческому разделу под наименованием «анализ бесконечно малых», объединяет дифференциальное  и интегральное исчисления."};
    std::string str2{"Теорема Ньютона — Лейбница, которую также называют основной теоремой анализа утверждает, что дифференцирование и интегрирование являются взаимно обратными операциями. Точнее, это касается значения первообразных для определённых интегралов."};
    std::string str3{"Математический анализ широко применяется в физике, информатике, статистике, технике, экономике, бизнесе, финансах, медицине, демографии и других областях, в которых для решения проблемы может быть построена математическая модель, и необходимо найти её оптимальное решение."};
    
    std::string rr;
    std::string temp;

    rr.append(str3, 99, 2);
    rr.append(str1, 99, 3);
    rr.pop_back();
    rr.push_back('р');
    rr += ' ';
    rr.insert(rr.end(), str2[str2.find('г')]);
    temp.assign(str3.begin() + 87, str3.end() - 182);
    temp.replace(temp.end() - 1, temp.end(), "на");
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
    rr.append(1, str2[str2.find('ь') + 1]);
    rr.push_back((rr.size() < rr.max_size()) + 31);
    rr.append(str1.data() + 1, 2);
    rr.replace(rr.size() - 1, rr.size(), 1, str3.at(29));

    std::cout << rr << std::endl;
}