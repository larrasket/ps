vector<string> solution(vector<string> picture) {
    int ln(picture[0].size());
    string row = string(ln + 2, '*');
    picture.insert(picture.begin(), row);
    picture.push_back(row);
    int n = picture.size();
    for (int i = 1 ; i < n-1; i++) {
        picture[i] = "*" + picture[i] + "*";
    }
    return picture;
}
