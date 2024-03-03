#include "UI.h"

void UserInterface::setUp()
{

	QHBoxLayout* mainLy = new QHBoxLayout;
	

	lista->setModel(model);
	mainLy->addWidget(lista);

	QVBoxLayout* scndly = new QVBoxLayout;

	scndly->addWidget(new QLabel{ "Rank:" });
	scndly->addWidget(sliderRank);
	mainLy->addLayout(scndly);

	sliderRank->setMaximum(10);
	sliderRank->setMinimum(1);
	sliderRank->setTickInterval(1);

	QVBoxLayout* thrdly = new QVBoxLayout;
	QFormLayout* formly = new QFormLayout;

	formly->addRow("Titlu:", titluTxt);
	thrdly->addLayout(formly);
	mainLy->addLayout(thrdly);

	thrdly->addWidget(modificaBtn);
	thrdly->addWidget(stergeBtn);
	thrdly->addWidget(undoBtn);

	QVBoxLayout* marely = new QVBoxLayout;
	setLayout(marely);

	marely->addLayout(mainLy);
	marely->addStretch(2);

}

void UserInterface::connectMethods()
{
	QObject::connect(lista->selectionModel(), &QItemSelectionModel::selectionChanged, [&]()
		{
			qDebug() << "selection changed";
			if (lista->selectionModel()->selectedIndexes().isEmpty())
			{
				titluTxt->setText("");
				sliderRank->setSliderPosition(1);
				return;
			}

			int selRow = lista->selectionModel()->selectedIndexes().at(0).row();

			auto titlu_index = lista->model()->index(selRow, 1);
			auto titlu = lista->model()->data(titlu_index, Qt::DisplayRole).toString();
			titluTxt->setText(titlu);

			auto id_index = lista->model()->index(selRow, 0);
			auto id = lista->model()->data(id_index, Qt::DisplayRole).toString();
			idTxt->setText(id);

			auto rank_index = lista->model()->index(selRow, 3);
			auto rank = lista->model()->data(rank_index, Qt::DisplayRole).toInt();

			sliderRank->setSliderPosition(rank);
		});

	QObject::connect(modificaBtn, &QPushButton::clicked, [&]()
		{
			if (idTxt->text() == "")
				return;

			auto id = idTxt->text().toInt();
			auto titlu = titluTxt->text().toStdString();
			auto rank = sliderRank->value();

			idTxt->clear();
			titluTxt->clear();

			serv.modifica_titlu_si_rank_serv(id, titlu, rank);

			model->setMlds();
			repaint();
		});

	QObject::connect(undoBtn, &QPushButton::clicked, [&]()
		{
			serv.undo();
			model->setMlds();
			repaint();
		});

	QObject::connect(stergeBtn, &QPushButton::clicked, [&]()
		{
			if (idTxt->text() == "")
				return;

			auto id = idTxt->text().toInt();
			idTxt->clear();
			titluTxt->clear();

			try
			{
				serv.sterge_melodie_serv(id);
			}
			catch (std::exception e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}

			model->setMlds();
			repaint();
		});
}


void UserInterface::paintEvent(QPaintEvent* ev)
{
	QPainter p{ this };

	for (int rank = 1; rank <= 10; rank++)
	{
		int ap = serv.cate_cu_acest_rank(rank);

		p.drawRect(10 + 40*(rank-1), height() - 20 * ap - 10, 20, 20 * ap);
	}
}

