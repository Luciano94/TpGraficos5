#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include <ScoreManager.h>
#include <Score.h>
#include <vector>

using namespace std;
using namespace nana;

int main() {
	ScoreManager* scoreManager = new ScoreManager();
	scoreManager->CreateScore("JOHN"); scoreManager->UpdateScore("JOHN", 10);
	scoreManager->CreateScore("MARIE"); scoreManager->UpdateScore("MARIE", 20);
	scoreManager->CreateScore("SOPHIE"); scoreManager->UpdateScore("SOPHIE", 150);
	scoreManager->CreateScore("RICHARD"); scoreManager->UpdateScore("RICHARD", 80);
	scoreManager->CreateScore("ANNIE"); scoreManager->UpdateScore("ANNIE", 15);
	scoreManager->CreateScore("JAX"); scoreManager->UpdateScore("JAX", 20);
	scoreManager->CreateScore("RAUL"); scoreManager->UpdateScore("RAUL", 60);
	vector<Score> scores;
	scoreManager->GetSortedDescending(scores);
	// form to hold everything
	form fm;
	// listbox to be the property grid
	listbox lb(fm, nana::rectangle(10, 10, 200, 100));

	// column headers
	lb.append_header("Name", 100);
	lb.append_header("score", 100);

	//Define a label and display a text.
	label lab{ fm, "<bold blue size=12>HighScore</>" };
	lab.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});

	for (vector<Score>::iterator it = scores.begin(); it != scores.end(); ++it) {

		lb.at(0).append({ (*it).name, to_string(static_cast<int>((*it).score)) });
	}
	place plc(fm);
	plc.div("< weight=5% def1>|<vert abc arrange=[20,130,20] gap=10>|< weight=5% def>");
	plc.field("abc") << lab << lb << btn;	//These buttons are children of fm.
	plc.collocate();
	fm.show();
	nana::exec();
}