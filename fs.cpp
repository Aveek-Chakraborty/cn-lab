#include <bits/stdc++.h>

using namespace std;




struct Frame {
    int id;
    string data;
};

void shuffleFrames(vector<Frame>& frames) {
    for (int i = frames.size() - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        swap(frames[i], frames[j]);
    }
}

void sortFrames(vector<Frame>& frames) {
    sort(frames.begin(), frames.end(), [](const Frame& a, const Frame& b) {
        return a.id < b.id;
    });
}

void showFrames(const vector<Frame>& frames) {
    cout << "\nframe_id \t frame_data \n";
    cout << "----------------------------\n";
    for (const auto& frame : frames) {
        cout << frame.id << "\t\t" << frame.data << "\n";
    }
}

int main() {
    srand(time(NULL));

    vector<Frame> frames;
    string msg;
    cout << "Enter a message: ";
    getline(cin, msg);

    int m = 0; // message iterator
    for (int i = 0; m < msg.length(); ++i) {
        Frame frame;
        frame.id = i;
        int fsize = rand() % 5 + 1; // variable Frame size in range [1,5]
        frame.data = msg.substr(m, fsize);
        m += fsize;
        frames.push_back(frame);
    }

    shuffleFrames(frames);
    cout << "\nShuffled frames:";
    showFrames(frames);

    sortFrames(frames);
    cout << "\nSorted frames:";
    showFrames(frames);

    cout << "\nFinal message: ";
    for (const auto& frame : frames) {
        cout << frame.data;
    }
    cout << "\n";

    return 0;
}
