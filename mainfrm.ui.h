#include <qfile.h>
#include <qmessagebox.h>
#include <qtextstream.h>

void mainfrm::charge_level()
{
	QString myrec;
	int compteur;
// *** Initialisations ***
	posx = 0;
	posy = 0;
	indicex = 0;
	indicey = 0;
	indice0 = 0;
	indice1 = 0;
	indice2 = 0;
	indice3 = 0;
	indice4 = 0;
	indice5 = 0;
	cpt_mur = 0;
	cpt_eau = 0;
	cpt_cube = 0;
	cpt_coeur = 0;
	cpt_autre = 0;
	cpt_glace = 0;
	cpt_bombe = 0;
	cpt_hache = 0;
	cpt_bateau_1 = 0;
	max_coeur = 0;
	ok = true;
	tmp01 = "";
	tmp02 = "";
	tmp03 = "";
	cpt_monstre_1 = 0;
	cpt_monstre_2 = 0;
	cpt_monstre_3 = 0;
	cpt_monstre_4 = 0;
	cpt_monstre_5 = 0;
	cpt_surprise = 0;
	cpt_cube_magique = 0;
	cpt_cube_neige = 0;
	nbre_surprise_prise = 0;
// *** Ouverture du fichier des niveaux ***
	QFile myfic("level.lev");
	if ( myfic.open( IO_ReadOnly ) )
	{
		QTextStream mystream (&myfic);
// *** Boucle recherche du nouveau niveau ***
		indice0 = 0;
		while (indice0 < culevel)
		{
			myrec = mystream.readLine();
			if (myrec.mid(0,3) == "$$$")
			{
				indice0 = indice0 + 1;
			}
		}
		myrec = mystream.readLine();
// *** Affichage de la porte ***
		mylab = new QLabel( this );
		QPixmap *mypix = new QPixmap("Images/porte.png");
        	mylab->setPixmap( *mypix );
        	mylab->setGeometry(48,576,48,48);
        	mylab->show();
		pntlab = mylab;
// *** Chargement du niveau ***
		while (!mystream.atEnd() && myrec.mid(0,3) != "$$$")
		{
			compteur = 0;
			while (myrec.mid(compteur,3) != "999" && myrec.mid(compteur,3) != "$$$")
			{
// *** Affichage des images **********************************************************
				if (myrec.mid(compteur,1) == "M")
				{
			        	mylab = new QLabel( this );
					if (indicex == 0 && indicey == 0)
					{
        					QPixmap *mypix = new QPixmap("Images/glacier_1.png");
        					mylab->setPixmap( *mypix );
        					mylab->setGeometry(posx,posy,48,48);
        					mylab->show();
						table_mur[cpt_mur] = mylab;
						cpt_mur = cpt_mur + 1;
					}
					else
					{
						if (indicex > 0 && indicex < 17 && indicey == 0)
						{
        						QPixmap *mypix = new QPixmap("Images/glacier_6.png");
        						mylab->setPixmap( *mypix );
        						mylab->setGeometry(posx,posy,48,48);
        						mylab->show();
							table_mur[cpt_mur] = mylab;
							cpt_mur = cpt_mur + 1;
						}
						else
						{
							if (indicex == 17 && indicey == 0)
							{
        						QPixmap *mypix = new QPixmap("Images/glacier_2.png");
        						mylab->setPixmap( *mypix );
        						mylab->setGeometry(posx,posy,48,48);
        						mylab->show();
							table_mur[cpt_mur] = mylab;
							cpt_mur = cpt_mur + 1;
							}
							else
							{
								if (indicex == 0 && indicey > 0 && indicey < 13)
								{
        								QPixmap *mypix = new QPixmap("Images/glacier_5.png");
        								mylab->setPixmap( *mypix );
        								mylab->setGeometry(posx,posy,48,48);
        								mylab->show();
									table_mur[cpt_mur] = mylab;
									cpt_mur = cpt_mur + 1;
								}
								else
								{
									if (indicex == 17 && indicey > 0 && indicey < 13)
									{
        									QPixmap *mypix = new QPixmap("Images/glacier_7.png");
        									mylab->setPixmap( *mypix );
        									mylab->setGeometry(posx,posy,48,48);
        									mylab->show();
										table_mur[cpt_mur] = mylab;
										cpt_mur = cpt_mur + 1;
									}
									else
									{
										if (indicex == 0 && indicey == 13)
										{
        										QPixmap *mypix = new QPixmap("Images/glacier_4.png");
        										mylab->setPixmap( *mypix );
        										mylab->setGeometry(posx,posy,48,48);
        										mylab->show();
											table_mur[cpt_mur] = mylab;
											cpt_mur = cpt_mur + 1;
										}
										else
										{
											if (indicex > 0 && indicex < 17 && indicey == 13)
											{
        											QPixmap *mypix = new QPixmap("Images/glacier_8.png");
        											mylab->setPixmap( *mypix );
        											mylab->setGeometry(posx,posy,48,48);
        											mylab->show();
												table_mur[cpt_mur] = mylab;
												cpt_mur = cpt_mur + 1;
											}
											else
											{
												if (indicex == 17 && indicey == 13)
												{
        												QPixmap *mypix = new QPixmap("Images/glacier_3.png");
        												mylab->setPixmap( *mypix );
        												mylab->setGeometry(posx,posy,48,48);
        												mylab->show();
													table_mur[cpt_mur] = mylab;
													cpt_mur = cpt_mur + 1;
												}
												else
												{
        												QPixmap *mypix = new QPixmap("Images/mur.png");
        												mylab->setPixmap( *mypix );
        												mylab->setGeometry(posx,posy,48,48);
        												mylab->show();
													table_mur[cpt_mur] = mylab;
													cpt_mur = cpt_mur + 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
//
				if (myrec.mid(compteur,2) == "FG")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/fleche_gauche.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_autre[cpt_autre] = mylab;
					cpt_autre = cpt_autre + 1;
				}
//
				if (myrec.mid(compteur,2) == "FD")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/fleche_droite.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_autre[cpt_autre] = mylab;
					cpt_autre = cpt_autre + 1;
				}
//
				if (myrec.mid(compteur,2) == "FH")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/fleche_haut.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_autre[cpt_autre] = mylab;
					cpt_autre = cpt_autre + 1;
				}
//
				if (myrec.mid(compteur,2) == "FB")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/fleche_bas.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_autre[cpt_autre] = mylab;
					cpt_autre = cpt_autre + 1;
				}
//
				if (myrec.mid(compteur,1) == "E")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_01_droite.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_1[cpt_monstre_1] = mylab;
					table_locmons_1[cpt_monstre_1][0] = indicex;
					table_locmons_1[cpt_monstre_1][1] = indicey;
					table_locmons_1[cpt_monstre_1][2] = 1;
					cpt_monstre_1 = cpt_monstre_1 + 1;
				}
//
				if (myrec.mid(compteur,1) == "Q")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/mouton_bas.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_5[cpt_monstre_5] = mylab;
					table_locmons_5[cpt_monstre_5][0] = indicex;
					table_locmons_5[cpt_monstre_5][1] = indicey;
					table_locmons_5[cpt_monstre_5][2] = 2;
					cpt_monstre_5 = cpt_monstre_5 + 1;
				}
//
				if (myrec.mid(compteur,1) == "P")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/mouton_droite.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_5[cpt_monstre_5] = mylab;
					table_locmons_5[cpt_monstre_5][0] = indicex;
					table_locmons_5[cpt_monstre_5][1] = indicey;
					table_locmons_5[cpt_monstre_5][2] = 1;
					cpt_monstre_5 = cpt_monstre_5 + 1;
				}
//
				if (myrec.mid(compteur,1) == "R")
				{
// *** Création d'un point d'eau ******************************************************
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/eau.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_autre[cpt_autre] = mylab;
					cpt_autre = cpt_autre + 1;
//
					table_locbato_1[cpt_bateau_1][0] = indicex;
					table_locbato_1[cpt_bateau_1][1] = indicey;
					table_locbato_1[cpt_bateau_1][2] = 1;
					table_locbato_2[cpt_bateau_1][0] = myrec.mid(compteur,3);
					cpt_bateau_1 = cpt_bateau_1 + 1;
				}
//
				if (myrec.mid(compteur,1) == "C")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/caisse.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_cube[cpt_cube] = mylab;
					cpt_cube = cpt_cube + 1;
				}
//
				if (myrec.mid(compteur,1) == "H")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/pioche.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_hache[cpt_hache] = mylab;
					cpt_hache = cpt_hache + 1;
				}
//
				if (myrec.mid(compteur,1) == "L")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/caisse_neige.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_cube_neige[cpt_cube_neige] = mylab;
					cpt_cube_neige = cpt_cube_neige + 1;
				}
//
				if (myrec.mid(compteur,1) == "T")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/cube.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_cube_magique[cpt_cube_magique] = mylab;
					table_loccubm_1[cpt_cube_magique][0] = indicex;
					table_loccubm_1[cpt_cube_magique][1] = indicey;
					cpt_cube_magique = cpt_cube_magique + 1;
				}
//
				if (myrec.mid(compteur,1) == "S")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/etoile.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_cube[cpt_cube] = mylab;
					cpt_cube = cpt_cube + 1;
				}
//
				if (myrec.mid(compteur,1) == "B")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/surprise.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_surprise[cpt_surprise] = mylab;
					cpt_surprise = cpt_surprise + 1;
				}
//
				if (myrec.mid(compteur,1) == "J")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/eau.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_eau[cpt_eau] = mylab;
					cpt_eau = cpt_eau + 1;
				}
//
				if (myrec.mid(compteur,1) == "W")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/glace.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_glace[cpt_glace] = mylab;
					cpt_glace = cpt_glace + 1;
				}
//
				if (myrec.mid(compteur,1) == "D")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_02_droite.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_2[cpt_monstre_2] = mylab;
					table_locmons_2[cpt_monstre_2][0] = indicex;
					table_locmons_2[cpt_monstre_2][1] = indicey;
					table_locmons_2[cpt_monstre_2][2] = 1;
					cpt_monstre_2 = cpt_monstre_2 + 1;
				}
//
				if (myrec.mid(compteur,1) == "N")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_02_haut.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_2[cpt_monstre_2] = mylab;
					table_locmons_2[cpt_monstre_2][0] = indicex;
					table_locmons_2[cpt_monstre_2][1] = indicey;
					table_locmons_2[cpt_monstre_2][2] = -2;
					cpt_monstre_2 = cpt_monstre_2 + 1;
				}
//
				if (myrec.mid(compteur,1) == "O")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_02_bas.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_2[cpt_monstre_2] = mylab;
					table_locmons_2[cpt_monstre_2][0] = indicex;
					table_locmons_2[cpt_monstre_2][1] = indicey;
					table_locmons_2[cpt_monstre_2][2] = 2;
					cpt_monstre_2 = cpt_monstre_2 + 1;
				}
//
				if (myrec.mid(compteur,1) == "Z")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_03_droite.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_3[cpt_monstre_3] = mylab;
					table_locmons_3[cpt_monstre_3][0] = indicex;
					table_locmons_3[cpt_monstre_3][1] = indicey;
					table_locmons_3[cpt_monstre_3][2] = 1;
					table_locmons_3[cpt_monstre_3][3] = 0;
					cpt_monstre_3 = cpt_monstre_3 + 1;
				}
//
				if (myrec.mid(compteur,1) == "G")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_02_gauche.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_2[cpt_monstre_2] = mylab;
					table_locmons_2[cpt_monstre_2][0] = indicex;
					table_locmons_2[cpt_monstre_2][1] = indicey;
					table_locmons_2[cpt_monstre_2][2] = -1;
					cpt_monstre_2 = cpt_monstre_2 + 1;
				}
//
				if (myrec.mid(compteur,1) == "I")
				{
					mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/monstre_04_SE.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_monstre_4[cpt_monstre_4] = mylab;
					table_locmons_4[cpt_monstre_4][0] = indicex;
					table_locmons_4[cpt_monstre_4][1] = indicey;
					table_locmons_4[cpt_monstre_4][2] = 1;
					table_locmons_4[cpt_monstre_4][3] = 1;
					cpt_monstre_4 = cpt_monstre_4 + 1;
				}
//
				if (myrec.mid(compteur,1) == "K")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/coeur.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_coeur[cpt_coeur] = mylab;
					cpt_coeur = cpt_coeur + 1;
				}
//
				if (myrec.mid(compteur,1) == "X")
				{
			        	mylab = new QLabel( this );
        				QPixmap *mypix = new QPixmap("Images/bombe.png");
        				mylab->setPixmap( *mypix );
        				mylab->setGeometry(posx,posy,48,48);
        				mylab->show();
					table_bombe[cpt_bombe] = mylab;
					cpt_bombe = cpt_bombe + 1;
				}
// *** Création du plateau en mémoire ************************************************
				if (myrec.mid(compteur,1) != "A")
				{
					plateau[indicex][indicey]=myrec.mid(compteur,3);
				}
				else
				{
					plateau[indicex][indicey]="0  ";
				}
				indicex=indicex+1;
// ***********************************************************************************
				compteur = compteur + 3;
				posx=posx+48;
			}			
// *** Changement de ligne d'affichage ***
			indicey=indicey+1;
			indicex=0;
			posy=posy+48;
			posx=0;
// *** Relecture du fichier ***
			myrec = mystream.readLine();
		}
// *** Sauvegarde de valeurs ***
		max_coeur = cpt_coeur;
// *** Affichage des bateaux ***
		indice0 = 0;
		while (indice0 < cpt_bateau_1)
		{
			indice1 = table_locbato_1[indice0][0];
			indice2 = table_locbato_1[indice0][1];
		       	mylab = new QLabel( this );
        		QPixmap *mypix = new QPixmap("Images/bateau_droite.png");
        		mylab->setPixmap( *mypix );
        		mylab->setGeometry(indice1 * 48,indice2 * 48,48,48);
        		mylab->show();
			table_bateau_1[indice0] = mylab;
			indice0 = indice0 + 1;
		}
// *** On affiche le héro ***
		posx = posx + 48;
		posy = posy - 96;
//
		mylab = new QLabel( this );
		mypix->load("Images/hero.png");
        	mylab->setPixmap( *mypix );
        	mylab->setGeometry(posx,posy,48,48);
        	mylab->show();
		pntlab = mylab;
		herox=1;
		heroy=12;
// *** Affichage du logo OK ***
		mylab = new QLabel( this );
		mypix->load("Images/ok.png");
		mylab->setPixmap( *mypix );
		mylab->setGeometry(746,623,100,48);
		mylab->show();
		pntpok = mylab;
		pntpok->hide();
// *** On affiche le OK ***
		if (progress.mid(culevel,1) == "1")
		{
			pntpok->show();
		}
// *** Déclenchement du timer ***
		if (cpt_monstre_1 > 0)
		{
        		mytimer->start( 100, FALSE );
		}
//
		if (cpt_monstre_3 > 0)
		{
        		mytimer_2->start( 200, FALSE );
		}
//
		if (cpt_monstre_4 > 0)
		{
        		mytimer_3->start( 200, FALSE );
		}
//
		if (cpt_bateau_1 > 0)
		{
        		mytimer_4->start( 700, FALSE );
		}
//
		if (cpt_monstre_5 > 0)
		{
        		mytimer_5->start( 400, FALSE );
		}
// *** Affichage des informations du level et autres ***
	info->setText("Level : " + QString::number(culevel));
	info_pouvoirs->setText("Pouvoirs : 0");
// *** Vidage mémoire ***
//	vidage();
// *** Fermeture du fichier ***
	myfic.close();
	}
	else
	{
		QMessageBox::warning(this, "Anomalie", "Le fichier des levels n'existe pas ...");
	}
}

void mainfrm::keyPressEvent( QKeyEvent *k )
{
	
// *** Gestion du clavier ************************************************************

        if ( k->text() == "6" || k->key() == Qt::Key_Right)
        {
		if (plateau[herox+1][heroy] == "0  ")
		{
			posx = posx + 48;
			herox = herox + 1;
                	pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
			ctrl_deplacement(1,0);
		}
        }

        if ( k->text() == "4" || k->key() == Qt::Key_Left)
        {
		if (plateau[herox-1][heroy] == "0  ")
		{
			posx = posx - 48;
			herox = herox - 1;
                	pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
			ctrl_deplacement(-1,0);
		}		
        }

        if ( k->text() == "8" || k->key() == Qt::Key_Up)
        {
		if (plateau[herox][heroy-1] == "0  ")
		{
			posy = posy - 48;
			heroy = heroy - 1;
                	pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
			ctrl_deplacement(0,-1);
		}
        }

        if ( k->text() == "2" || k->key() == Qt::Key_Down)
        {
		if (plateau[herox][heroy+1] == "0  ")
		{
			posy = posy + 48;
			heroy = heroy + 1;
                	pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
			ctrl_deplacement(0,1);
		}
        }

        if ( k->text() == "5" || k->key() == Qt::Key_Space)
        {
		ctrl_surprise();
        }

	if ( k->key() == Qt::Key_Escape)
	{
		cassetout();
	}

	if (herox == 1 && heroy == 12 && cpt_coeur == 0)
	{
		if (mytimer->isActive())
		{
			mytimer->stop();
		}
		if (mytimer_2->isActive())
		{
			mytimer_2->stop();
		}
		if (mytimer_3->isActive())
		{
			mytimer_3->stop();
		}
		if (mytimer_4->isActive())
		{
			mytimer_4->stop();
		}
		if (mytimer_5->isActive())
		{
			mytimer_5->stop();
		}
// *** Enregistrement de la progression dans le jeu ***
		progress.replace(culevel,1,"1");
		QFile myfic("data.dat");

		if ( myfic.open( IO_WriteOnly ))
		{
			myfic.writeBlock(progress,49);
			myfic.close();
		}
		else
		{
			QMessageBox::warning(this, "Anomalie", "Je n arrive pas a créer le fichier de progression ...");
		}
		if (culevel < 48)
		{
			culevel = culevel + 1;
		}
		else
		{
			culevel = 0;
		}
		QMessageBox::warning(this, "Victoire", "Bravo level réussi ...");
		if (progress == "1111111111111111111111111111111111111111111111111")
		{
			QMessageBox::warning(this, "Bravo", "Champion du monde ! Vous avez terminé le jeu. Mais il y aura une suite, alors a bientôt ...");
		}
		cassetout();
	}

}

void mainfrm::ctrl_surprise()
{
// *** Contrôle présence d'étoile au est,ouest,nord,sud autour du héro ***

// *** EST ***
	tmp01 = plateau[herox + 1][heroy];

	if (tmp01.mid(0,1) == "S" && nbre_surprise_prise > 0)
	{
		tmp03 = tmp01.mid(1,2);
		indice0 = tmp03.toInt( &ok, 10);
		pntdep = table_cube[indice0];
        	QPixmap *mypix = new QPixmap("Images/caisse.png");
        	pntdep->setPixmap( *mypix );
		tmp02 = "C" + tmp01.mid(1,2);
		plateau[herox + 1][heroy] = tmp02;
		nbre_surprise_prise = nbre_surprise_prise - 1;
		info_pouvoirs->setText("Pouvoirs : " + QString::number(nbre_surprise_prise));	
	}

// *** OUEST ***
	tmp01 = plateau[herox - 1][heroy];

	if (tmp01.mid(0,1) == "S" && nbre_surprise_prise > 0)
	{
		tmp03 = tmp01.mid(1,2);
		indice0 = tmp03.toInt( &ok, 10);
		pntdep = table_cube[indice0];
        	QPixmap *mypix = new QPixmap("Images/caisse.png");
        	pntdep->setPixmap( *mypix );
		tmp02 = "C" + tmp01.mid(1,2);
		plateau[herox - 1][heroy] = tmp02;
		nbre_surprise_prise = nbre_surprise_prise - 1;
		info_pouvoirs->setText("Pouvoirs : " + QString::number(nbre_surprise_prise));	
	}

// *** NORD ***
	tmp01 = plateau[herox][heroy - 1];

	if (tmp01.mid(0,1) == "S" && nbre_surprise_prise > 0)
	{
		tmp03 = tmp01.mid(1,2);
		indice0 = tmp03.toInt( &ok, 10);
		pntdep = table_cube[indice0];
        	QPixmap *mypix = new QPixmap("Images/caisse.png");
        	pntdep->setPixmap( *mypix );
		tmp02 = "C" + tmp01.mid(1,2);
		plateau[herox][heroy - 1] = tmp02;
		nbre_surprise_prise = nbre_surprise_prise - 1;
		info_pouvoirs->setText("Pouvoirs : " + QString::number(nbre_surprise_prise));	
	}

// *** SUD ***
	tmp01 = plateau[herox][heroy + 1];

	if (tmp01.mid(0,1) == "S" && nbre_surprise_prise > 0)
	{
		tmp03 = tmp01.mid(1,2);
		indice0 = tmp03.toInt( &ok, 10);
		pntdep = table_cube[indice0];
        	QPixmap *mypix = new QPixmap("Images/caisse.png");
        	pntdep->setPixmap( *mypix );
		tmp02 = "C" + tmp01.mid(1,2);
		plateau[herox][heroy+1] = tmp02;
		nbre_surprise_prise = nbre_surprise_prise - 1;
		info_pouvoirs->setText("Pouvoirs : " + QString::number(nbre_surprise_prise));	
	}
}

void mainfrm::move_ennemis()
{
// *** Déplacement des monstres 1 ************************************
	indice0=0;

	while (indice0 < cpt_monstre_1)
	{
		indice1 = table_locmons_1[indice0][0];
		indice2 = table_locmons_1[indice0][1];
		indice3 = table_locmons_1[indice0][2];
		
		if (plateau[indice1 + indice3][indice2] == "0  ")
		{
			pntdep = table_monstre_1[indice0];
			plateau[indice1 + indice3][indice2] = plateau[indice1][indice2];
			plateau[indice1][indice2] = "0  ";
			pntdep->setGeometry(0 + ((indice1 + indice3)*48),0 + (indice2*48),48,48);
			table_locmons_1[indice0][0] = indice1 + indice3;
		}
		else
		{
			table_locmons_1[indice0][2] = table_locmons_1[indice0][2] * -1;
			pntdep = table_monstre_1[indice0];
			if (table_locmons_1[indice0][2] < 0)
			{
				QPixmap *mypix = new QPixmap("Images/monstre_01_gauche.png");
        			pntdep->setPixmap( *mypix );
			}
			else
			{
				QPixmap *mypix = new QPixmap("Images/monstre_01_droite.png");
        			pntdep->setPixmap( *mypix );
			}
		}

// *** Test collision avec le héro *********************************
		if (herox == (indice1 + indice3) && heroy == indice2)
		{
			if (mytimer->isActive())
			{
				mytimer->stop();
			}
			if (mytimer_2->isActive())
			{
				mytimer_2->stop();
			}
			if (mytimer_3->isActive())
			{
				mytimer_3->stop();
			}
			if (mytimer_4->isActive())
			{
				mytimer_4->stop();
			}
			if (mytimer_5->isActive())
			{
				mytimer_5->stop();
			}
			QMessageBox::warning(this, "Ouie ca fait mal", "Je t'ai mangé petit pinguin !");
			cassetout();
		}
		indice0 = indice0 + 1;
	}
}

void mainfrm::move_ennemis_3()
{
// *** Déplacement des monstres 3 ************************************
	indice0=0;

	while (indice0 < cpt_monstre_3)
	{
		indice1 = table_locmons_3[indice0][0];
		indice2 = table_locmons_3[indice0][1];
		indice3 = table_locmons_3[indice0][2];
		indice4 = table_locmons_3[indice0][3];
		
		if (plateau[indice1 + indice3][indice2 + indice4] == "0  ")
		{
			pntdep = table_monstre_3[indice0];
			plateau[indice1 + indice3][indice2 + indice4] = plateau[indice1][indice2];
			plateau[indice1][indice2] = "0  ";
			pntdep->setGeometry(0 + ((indice1 + indice3)*48),0 + ((indice2 + indice4)*48),48,48);
			table_locmons_3[indice0][0] = indice1 + indice3;
			table_locmons_3[indice0][1] = indice2 + indice4;
		}
		else
		{
			pntdep = table_monstre_3[indice0];
			if (table_locmons_3[indice0][2] == 1)
			{
				table_locmons_3[indice0][2] = 0;
				table_locmons_3[indice0][3] = 1;
				QPixmap *mypix = new QPixmap("Images/monstre_03_bas.png");
        			pntdep->setPixmap( *mypix );
			}
			else
			{
				if (table_locmons_3[indice0][3] == 1)
				{
					table_locmons_3[indice0][2] = -1;
					table_locmons_3[indice0][3] = 0;
					QPixmap *mypix = new QPixmap("Images/monstre_03_gauche.png");
        				pntdep->setPixmap( *mypix );
				}
				else
				{
					if (table_locmons_3[indice0][2] == -1)
					{
						table_locmons_3[indice0][2] = 0;
						table_locmons_3[indice0][3] = -1;
						QPixmap *mypix = new QPixmap("Images/monstre_03_haut.png");
        					pntdep->setPixmap( *mypix );
					}
					else
					{
						if (table_locmons_3[indice0][3] == -1)
						{
							table_locmons_3[indice0][2] = 1;
							table_locmons_3[indice0][3] = 0;
							QPixmap *mypix = new QPixmap("Images/monstre_03_droite.png");
        						pntdep->setPixmap( *mypix );
						}
					}
				}
			}
		}

// *** Test collision avec le héro *********************************
		if (herox == (indice1 + indice3) && heroy == (indice2 + indice4))
		{
			if (mytimer->isActive())
			{
				mytimer->stop();
			}
			if (mytimer_2->isActive())
			{
				mytimer_2->stop();
			}
			if (mytimer_3->isActive())
			{
				mytimer_3->stop();
			}
			if (mytimer_4->isActive())
			{
				mytimer_4->stop();
			}
			if (mytimer_5->isActive())
			{
				mytimer_5->stop();
			}
			QMessageBox::warning(this, "Ouie ca fait mal", "Je t'ai mangé petit pinguin !");
			cassetout();
		}
		indice0 = indice0 + 1;
	}
}

void mainfrm::move_bateaux_1()
{
// *** Déplacement des bateaux ************************************
	indice0=0;
	while (indice0 < cpt_bateau_1)
	{
		indice1 = table_locbato_1[indice0][0];
		indice2 = table_locbato_1[indice0][1];
		indice3 = table_locbato_1[indice0][2];
		
		tmp01 = plateau[indice1 + indice3][indice2];
		if (tmp01.mid(0,1) == "J" || tmp01.mid(0,1) == "R")
		{
			pntdep = table_bateau_1[indice0];
			pntdep->setGeometry((indice1 + indice3)*48,(indice2*48),48,48);
			plateau[indice1][indice2] = table_locbato_2[indice0][0];
			table_locbato_2[indice0][0] = plateau[indice1 + indice3][indice2];
			tmp02 = "R00";
			tmp02.mid(2,1) = indice0;
			plateau[indice1 + indice3][indice2] = tmp02;
			
			table_locbato_1[indice0][0] = indice1 + indice3;
		}
		else
		{
			pntdep = table_bateau_1[indice0];
			if (table_locbato_1[indice0][2] == 1)
			{
				table_locbato_1[indice0][2] = -1;
				QPixmap *mypix = new QPixmap("Images/bateau_gauche.png");
        			pntdep->setPixmap( *mypix );
			}
			else
			{
				table_locbato_1[indice0][2] = 1;
				QPixmap *mypix = new QPixmap("Images/bateau_droite.png");
        			pntdep->setPixmap( *mypix );
			}
		}
		ctrl_poissons();
		indice0 = indice0 + 1;
	}
}

void mainfrm::move_ennemis_4()
{
// *** Déplacement des monstres 4 ************************************
	indice0=0;

	while (indice0 < cpt_monstre_4)
	{
		indice1 = table_locmons_4[indice0][0];
		indice2 = table_locmons_4[indice0][1];
		indice3 = table_locmons_4[indice0][2];
		indice4 = table_locmons_4[indice0][3];
		
		if (plateau[indice1 + indice3][indice2 + indice4] == "0  ")
		{
			pntdep = table_monstre_4[indice0];
			plateau[indice1 + indice3][indice2 + indice4] = plateau[indice1][indice2];
			plateau[indice1][indice2] = "0  ";
			pntdep->setGeometry(0 + ((indice1 + indice3)*48),0 + ((indice2 + indice4)*48),48,48);
			table_locmons_4[indice0][0] = indice1 + indice3;
			table_locmons_4[indice0][1] = indice2 + indice4;
		}
		else
		{
// *** Test si on a rencontré de la glace *****************************
			tmp02 = plateau[indice1 + indice3][indice2 + indice4];
			if(tmp02.mid(0,1) == "W")
			{
				tmp03 = tmp02.mid(1,2);
				indice5 = tmp03.toInt( &ok, 10);
				pntdep = table_glace[indice5];
				pntdep->hide();
				plateau[indice1 + indice3][indice2 + indice4] = "0  ";
			}
			tmp02 = plateau[indice1 + indice3][indice2];
			if(tmp02.mid(0,1) == "W")
			{
				tmp03 = tmp02.mid(1,2);
				indice5 = tmp03.toInt( &ok, 10);
				pntdep = table_glace[indice5];
				pntdep->hide();
				plateau[indice1 + indice3][indice2] = "0  ";
			}
			tmp02 = plateau[indice1][indice2 + indice4];
			if(tmp02.mid(0,1) == "W")
			{
				tmp03 = tmp02.mid(1,2);
				indice5 = tmp03.toInt( &ok, 10);
				pntdep = table_glace[indice5];
				pntdep->hide();
				plateau[indice1][indice2 + indice4] = "0  ";
			}
//
			if (plateau[indice1 + indice3][indice2] != "0  ") 
			{
				table_locmons_4[indice0][2] = table_locmons_4[indice0][2] * -1;
			}
			else
			{
				if (plateau[indice1][indice2 + indice4] != "0  ") 
				{
					table_locmons_4[indice0][3] = table_locmons_4[indice0][3] * -1;
				}
				else
				{
					table_locmons_4[indice0][2] = table_locmons_4[indice0][2] * -1;
					table_locmons_4[indice0][3] = table_locmons_4[indice0][3] * -1;
				}
			}
//
			pntdep = table_monstre_4[indice0];

			if (table_locmons_4[indice0][2] > 0 && table_locmons_4[indice0][3] < 0)
			{
				QPixmap *mypix = new QPixmap("Images/monstre_04_NE.png");
        			pntdep->setPixmap( *mypix );
			}
			else
			{
				if (table_locmons_4[indice0][2] > 0 && table_locmons_4[indice0][3] > 0)
				{
					QPixmap *mypix = new QPixmap("Images/monstre_04_SE.png");
        				pntdep->setPixmap( *mypix );
				}
				else
				{
					if (table_locmons_4[indice0][2] < 0 && table_locmons_4[indice0][3] < 0)
					{
						QPixmap *mypix = new QPixmap("Images/monstre_04_NW.png");
        					pntdep->setPixmap( *mypix );
					}
					else
					{
						QPixmap *mypix = new QPixmap("Images/monstre_04_SW.png");
        					pntdep->setPixmap( *mypix );
					}
				}
			}
		}

// *** Test collision avec le héro *********************************
		if (herox == (indice1 + indice3) && heroy == (indice2 + indice4))
		{
			if (mytimer->isActive())
			{
				mytimer->stop();
			}
			if (mytimer_2->isActive())
			{
				mytimer_2->stop();
			}
			if (mytimer_3->isActive())
			{
				mytimer_3->stop();
			}
			if (mytimer_4->isActive())
			{
				mytimer_4->stop();
			}
			if (mytimer_5->isActive())
			{
				mytimer_5->stop();
			}
			QMessageBox::warning(this, "Ouie ca fait mal", "Je t'ai mangé petit pinguin !");
			cassetout();
		}
		indice0 = indice0 + 1;
	}
}

void mainfrm::move_ennemis_5()
{
// *** Déplacement des bateaux ************************************
	indice0=0;
	while (indice0 < cpt_monstre_5)
	{
		indice1 = table_locmons_5[indice0][0];
		indice2 = table_locmons_5[indice0][1];
		indice3 = table_locmons_5[indice0][2];
		tmp04 = "0";

		if (indice3 == 1 || indice3 == -1)
		{
			tmp01 = plateau[indice1 + indice3][indice2];
			if (herox == (indice1 + indice3) && heroy == indice2)
			{
				tmp04 = "1";
			}
		}
		else
		{
			tmp01 = plateau[indice1][indice2 + (indice3 / 2)];
			if (herox == indice1 && heroy == (indice2 + (indice3 / 2)))
			{
				tmp04 = "1";
			}
		}
		if ((tmp01.mid(0,1) == "0" || tmp01.mid(0,1) == "C") && tmp04 == "0")
		{
			pntdep = table_monstre_5[indice0];
			if (indice3 == 1 || indice3 == -1)
			{
				if (tmp01.mid(0,1) == "0")
				{
					pntdep->setGeometry((indice1 + indice3)*48,(indice2*48),48,48);
					plateau[indice1 + indice3][indice2] = plateau[indice1][indice2];
					plateau[indice1][indice2] = "0  ";
					table_locmons_5[indice0][0] = indice1 + indice3;
				}
				else
				{
					if (herox == (indice1 + (indice3*2)) && heroy == indice2)
					{
						tmp04 = "1";
					}
					tmp02 = plateau[indice1 + (indice3*2)][indice2];
					if (tmp02.mid(0,1) == "0" & tmp04 == "0")
					{
						tmp03 = tmp01.mid(1,2);
						indice5 = tmp03.toInt( &ok, 10);
						pntdep = table_cube[indice5];
						pntdep->setGeometry((indice1 + (indice3*2))*48,(indice2*48),48,48);
						plateau[indice1 + (indice3*2)][indice2] = plateau[indice1 + indice3][indice2];
						plateau[indice1 + indice3][indice2] = "0  ";
//
						pntdep = table_monstre_5[indice0];
						pntdep->setGeometry((indice1 + indice3)*48,(indice2*48),48,48);
						plateau[indice1 + indice3][indice2] = plateau[indice1][indice2];
						plateau[indice1][indice2] = "0  ";
						table_locmons_5[indice0][0] = indice1 + indice3;
					}
					else
					{
						pntdep = table_monstre_5[indice0];
						if (table_locmons_5[indice0][2] == 1)
						{
							table_locmons_5[indice0][2] = -1;
							QPixmap *mypix = new QPixmap("Images/mouton_gauche.png");
        						pntdep->setPixmap( *mypix );
						}
						else
						{
							table_locmons_5[indice0][2] = 1;
							QPixmap *mypix = new QPixmap("Images/mouton_droite.png");
        						pntdep->setPixmap( *mypix );
						}
					}
				}
			}
			else
			{
				if (tmp01.mid(0,1) == "0")
				{
					pntdep->setGeometry((indice1)*48,((indice2  + (indice3 / 2))*48),48,48);
					plateau[indice1][indice2 + (indice3 / 2)] = plateau[indice1][indice2];
					plateau[indice1][indice2] = "0  ";
					table_locmons_5[indice0][1] = indice2 + (indice3 / 2);
				}
				else
				{
					if (herox == indice1 && heroy == (indice2 + indice3))
					{
						tmp04 = "1";
					}
					tmp02 = plateau[indice1][indice2 + indice3];
					if (tmp02.mid(0,1) == "0" && tmp04 == "0")
					{
						tmp03 = tmp01.mid(1,2);
						indice5 = tmp03.toInt( &ok, 10);
						pntdep = table_cube[indice5];
						pntdep->setGeometry(indice1*48,((indice2 + indice3)*48),48,48);
						plateau[indice1][indice2 + indice3] = plateau[indice1][indice2 + (indice3 / 2)];
						plateau[indice1][indice2 + (indice3 / 2)] = "0  ";
//
						pntdep = table_monstre_5[indice0];
						pntdep->setGeometry((indice1)*48,((indice2  + (indice3 / 2))*48),48,48);
						plateau[indice1][indice2 + (indice3 / 2)] = plateau[indice1][indice2];
						plateau[indice1][indice2] = "0  ";
						table_locmons_5[indice0][1] = indice2 + (indice3 / 2);
					}
					else
					{
						pntdep = table_monstre_5[indice0];
						if (table_locmons_5[indice0][2] == 2)
						{
							table_locmons_5[indice0][2] = -2;
							QPixmap *mypix = new QPixmap("Images/mouton_haut.png");
        						pntdep->setPixmap( *mypix );
						}
						else
						{
							table_locmons_5[indice0][2] = 2;
							QPixmap *mypix = new QPixmap("Images/mouton_bas.png");
        						pntdep->setPixmap( *mypix );
						}
					}
				}
			}		
		}
		else
		{
			pntdep = table_monstre_5[indice0];
			if (table_locmons_5[indice0][2] == 1)
			{
				table_locmons_5[indice0][2] = -1;
				QPixmap *mypix = new QPixmap("Images/mouton_gauche.png");
        			pntdep->setPixmap( *mypix );
			}
			else
			{
				if (table_locmons_5[indice0][2] == -1)
				{
					table_locmons_5[indice0][2] = 1;
					QPixmap *mypix = new QPixmap("Images/mouton_droite.png");
        				pntdep->setPixmap( *mypix );
				}
				else
				{
					if (table_locmons_5[indice0][2] == 2)
					{
						table_locmons_5[indice0][2] = -2;
						QPixmap *mypix = new QPixmap("Images/mouton_haut.png");
        					pntdep->setPixmap( *mypix );
					}
					else
					{
						table_locmons_5[indice0][2] = 2;
						QPixmap *mypix = new QPixmap("Images/mouton_bas.png");
        					pntdep->setPixmap( *mypix );
					}
				}
			}
		}
		indice0 = indice0 + 1;
	}
}

void mainfrm::ctrl_poissons()
{

// *** Contrôle des poissons ***************************************
	indice0 = 0;
	while (indice0 < cpt_monstre_2)
	{
		indice1 = table_locmons_2[indice0][0];
		indice2 = table_locmons_2[indice0][1];
		indice3 = table_locmons_2[indice0][2];
		
		if (indice3 == -1 || indice3 == 1)
		{
			indice1 = indice1 + indice3;
		}
		else
		{
			indice2 = indice2 + (indice3 / 2);
		}
		
		while (indice3 < 4)
		{
			tmp02 = plateau[indice1][indice2];
			if (tmp02.mid(0,1) != "0" && tmp02.mid(0,1) != "J")
			{
				indice3 = 4;
			}
			if (herox == indice1 && heroy == indice2)
			{
				indice3 = 4;
			}
			else
			{
				if (indice3 == -1 || indice3 == 1)
				{
					indice1 = indice1 + indice3;
			
				}
				else
				{
					if (indice3 == -2 || indice3 == 2)
					{
						indice2 = indice2 + (indice3 / 2);
					}
				}
			}
		}
// *** Test collision avec le héro *********************************
		if (herox == indice1 && heroy == indice2)
		{
			if (mytimer->isActive())
			{
				mytimer->stop();
			}
			if (mytimer_2->isActive())
			{
				mytimer_2->stop();
			}
			if (mytimer_3->isActive())
			{
				mytimer_3->stop();
			}
			if (mytimer_4->isActive())
			{
				mytimer_4->stop();
			}
			if (mytimer_5->isActive())
			{
				mytimer_5->stop();
			}
			QMessageBox::warning(this, "Ouie ca fait mal", "Pan un boulet dans la tête !");
			cassetout();
		}
		indice0 = indice0 + 1;
	}

}

void mainfrm::ctrl_deplacement( int depx, int depy )
{
// *** Test du sens du déplacement *********************************
	tmp01 = plateau[herox + depx][heroy + depy];
	if (tmp01.mid(0,1) == "C")
	{
		tmp02 = plateau[herox + (depx*2)][heroy + (depy*2)];
		if (tmp02.mid(0,1) == "0")
		{
			tmp03 = tmp01.mid(1,2);
			indice0 = tmp03.toInt( &ok, 10);
			pntdep = table_cube[indice0];
			pntdep->setGeometry(posx+(96*depx),posy+(96*depy),48,48);
			plateau[herox + (depx*2)][heroy + (depy*2)] = plateau[herox + depx][heroy + depy];
			plateau[herox + depx][heroy + depy] = "0  ";
// *** Calculs de position et déplacement du héro ******************
			posx = posx + (48 * depx);
			posy = posy + (48 * depy);
			herox = herox + depx;
			heroy = heroy + depy;
			pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
// *** On rencontre de l'eau ***************************************
			if (tmp02.mid(0,1) == "J")
			{
				tmp03 = tmp02.mid(1,2);
				indice0 = tmp03.toInt( &ok, 10);
				pntdep = table_eau[indice0];
				pntdep->hide();
//
				tmp03 = tmp01.mid(1,2);
				indice0 = tmp03.toInt( &ok, 10);
				pntdep = table_cube[indice0];
//				pntdep->setGeometry(posx+(96*depx),posy+(96*depy),48,48);
//        			pntdep->setPixmap( *mypix );
				pntdep->hide();
				plateau[herox + (depx*2)][heroy + (depy*2)] = "0  ";
				plateau[herox + depx][heroy + depy] = "0  ";
// *** Calculs de position et déplacement du héro ******************
				posx = posx + (48 * depx);
				posy = posy + (48 * depy);
				herox = herox + depx;
				heroy = heroy + depy;
				pntlab->setGeometry(posx,posy,48,48);
				ctrl_poissons();
			}
		}
	}
	else
	{
		if (tmp01.mid(0,1) == "K")
		{
			tmp03 = tmp01.mid(1,2);
			indice0 = tmp03.toInt( &ok, 10);
			pntdep = table_coeur[indice0];
			pntdep->hide();
			plateau[herox + depx][heroy + depy] = "0  ";
// *** On décrémente le nombre de coeurs restant *******************
			cpt_coeur = cpt_coeur - 1;
// *** Calculs de position et déplacement du héro ******************
			posx = posx + (48 * depx);
			posy = posy + (48 * depy);
			herox = herox + depx;
			heroy = heroy + depy;
			pntlab->setGeometry(posx,posy,48,48);
			ctrl_poissons();
		}
		else
		{
			if (tmp01.mid(0,1) == "B")
			{
				tmp03 = tmp01.mid(1,2);
				indice0 = tmp03.toInt( &ok, 10);
				pntdep = table_surprise[indice0];
				pntdep->hide();
				plateau[herox + depx][heroy + depy] = "0  ";
				nbre_surprise_prise = nbre_surprise_prise + 1;
				info_pouvoirs->setText("Pouvoirs : " + QString::number(nbre_surprise_prise));
// *** Calculs de position et déplacement du héro ******************
				posx = posx + (48 * depx);
				posy = posy + (48 * depy);
				herox = herox + depx;
				heroy = heroy + depy;
				pntlab->setGeometry(posx,posy,48,48);
				ctrl_poissons();
			}
			else
			{
				if (tmp01.mid(0,2) == "FD")
				{
					if (depx == 1 || depy == 1 || depy == -1)
					{
						posx = posx + (48 * depx);
						posy = posy + (48 * depy);
						herox = herox + depx;
						heroy = heroy + depy;
						pntlab->setGeometry(posx,posy,48,48);
						ctrl_poissons();	
					}
				}
				else
				{
					if (tmp01.mid(0,2) == "FG")
					{
						if (depx == -1 || depy == 1 || depy == -1)
						{
							posx = posx + (48 * depx);
							posy = posy + (48 * depy);
							herox = herox + depx;
							heroy = heroy + depy;
							pntlab->setGeometry(posx,posy,48,48);
							ctrl_poissons();	
						}
					}
					else
					{
						if (tmp01.mid(0,1) == "T")
						{
							indice1 = 0;
							indice4 = 0;
// *** Test du cube poussé *******************************************************************
							tmp03 = tmp01.mid(1,2);
							indice5 = tmp03.toInt( &ok, 10);
							indice2 = table_loccubm_1[indice5][0];
							indice3 = table_loccubm_1[indice5][1];
							tmp02 = plateau[indice2 + depx][indice3 + depy];
							if (tmp02.mid(0,1) == "0")
							{
								pntdep = table_cube_magique[indice5];
								pntdep->setGeometry(0 + ((indice2 + depx)*48),0 + ((indice3 + depy)*48),48,48);
								plateau[indice2 + depx][indice3 + depy] = plateau[indice2][indice3];
								plateau[indice2][indice3] = "0  ";
								table_loccubm_1[indice5][0] = indice2 + depx;
								table_loccubm_1[indice5][1] = indice3 + depy;
								indice4 = 1;
							}

							while (indice1 < cpt_cube_magique && indice4 == 1)
							{
								if (indice1 != indice5)
								{
									indice2 = table_loccubm_1[indice1][0];
									indice3 = table_loccubm_1[indice1][1];
									tmp02 = plateau[indice2 + depx][indice3 + depy];

									if (tmp02.mid(0,1) == "0")
									{
										pntdep = table_cube_magique[indice1];
										pntdep->setGeometry(0 + ((indice2 + depx)*48),0 + ((indice3 + depy)*48),48,48);
										plateau[indice2 + depx][indice3 + depy] = plateau[indice2][indice3];
										plateau[indice2][indice3] = "0  ";
										table_loccubm_1[indice1][0] = indice2 + depx;
										table_loccubm_1[indice1][1] = indice3 + depy;
									}
								}
								indice1 = indice1 + 1;
							}
// *** DEPLACEMENT DU HERO *******************************************************************
							if (indice4 == 1)
							{
								posx = posx + (48 * depx);
								posy = posy + (48 * depy);
								herox = herox + depx;
								heroy = heroy + depy;
								pntlab->setGeometry(posx,posy,48,48);
								ctrl_poissons();
							}
						}
						else
						{
							if (tmp01.mid(0,2) == "FH")
							{
								if (depy == -1 || depx == 1 || depx == -1)
								{
									posx = posx + (48 * depx);
									posy = posy + (48 * depy);
									herox = herox + depx;
									heroy = heroy + depy;
									pntlab->setGeometry(posx,posy,48,48);
									ctrl_poissons();	
								}
							}
							else
							{
								if (tmp01.mid(0,2) == "FB")
								{
									if (depy == 1 || depx == 1 || depx == -1)
									{
										posx = posx + (48 * depx);
										posy = posy + (48 * depy);
										herox = herox + depx;
										heroy = heroy + depy;
										pntlab->setGeometry(posx,posy,48,48);
										ctrl_poissons();	
									}
								}
								else
								{
									if (tmp01.mid(0,1) == "L")
									{
										indice3 = herox + (depx*2);
										indice4 = heroy + (depy*2);
										tmp02 = plateau[indice3][indice4];
										while (tmp02.mid(0,1) == "0")
										{
											tmp03 = tmp01.mid(1,2);
											indice0 = tmp03.toInt( &ok, 10);
											pntdep = table_cube_neige[indice0];
											pntdep->setGeometry(0+(48*indice3),0+(48*indice4),48,48);
											plateau[indice3][indice4] = plateau[indice3 - depx][indice4 - depy];
											plateau[indice3 - depx][indice4 - depy] = "0  ";
											indice3 = indice3 + depx;
											indice4 = indice4 + depy;
											tmp02 = plateau[indice3][indice4];
										}
// *** Test si le cube glissant rencontre de la glace **************
										if(tmp02.mid(0,1) == "W")
										{
											tmp03 = tmp02.mid(1,2);
											indice0 = tmp03.toInt( &ok, 10);
											pntdep = table_glace[indice0];
											pntdep->hide();
											plateau[indice3][indice4] = "0  ";
											plateau[indice3 - depx][indice4 - depy] = "0  ";
											tmp03 = tmp01.mid(1,2);
											indice0 = tmp03.toInt( &ok, 10);
											pntdep = table_cube_neige[indice0];
											pntdep->hide();
										}
// *** Test si le cube glissant rencontre une bombe ***************
										if(tmp02.mid(0,1) == "X")
										{
											tmp03 = tmp02.mid(1,2);
											indice0 = tmp03.toInt( &ok, 10);
											pntdep = table_bombe[indice0];
											pntdep->hide();
											plateau[indice3][indice4] = "0  ";
											plateau[indice3 - depx][indice4 - depy] = "0  ";
											tmp03 = tmp01.mid(1,2);
											indice0 = tmp03.toInt( &ok, 10);
											pntdep = table_cube_neige[indice0];
											pntdep->hide();
//
											tmp02 = plateau[indice3 + 1][indice4];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 + 1][indice4] = "0  ";
											}

											tmp02 = plateau[indice3 - 1][indice4];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 - 1][indice4] = "0  ";
											}

											tmp02 = plateau[indice3][indice4 + 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3][indice4 + 1] = "0  ";
											}

											tmp02 = plateau[indice3][indice4 - 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3][indice4 - 1] = "0  ";
											}

											tmp02 = plateau[indice3 + 1][indice4 + 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 + 1][indice4 + 1] = "0  ";
											}

											tmp02 = plateau[indice3 - 1][indice4 - 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 - 1][indice4 - 1] = "0  ";
											}

											tmp02 = plateau[indice3 + 1][indice4 - 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 + 1][indice4 - 1] = "0  ";
											}

											tmp02 = plateau[indice3 - 1][indice4 + 1];
											if (tmp02.mid(0,1) == "W")
											{
												tmp03 = tmp02.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_glace[indice0];
												pntdep->hide();
												plateau[indice3 - 1][indice4 + 1] = "0  ";
											}
										}
// *** Calculs de position et déplacement du héro ******************
										indice3 = herox + depx;
										indice4 = heroy + depy;
										tmp02 = plateau[indice3][indice4];
										if (tmp02.mid(0,1) == "0")
										{
											posx = posx + (48 * depx);
											posy = posy + (48 * depy);
											herox = herox + depx;
											heroy = heroy + depy;
											pntlab->setGeometry(posx,posy,48,48);
											ctrl_poissons();
										}
									}
									else
									{
										if (tmp01.mid(0,1) == "X")
										{
											tmp02 = plateau[herox + (depx*2)][heroy + (depy*2)];
											if (tmp02.mid(0,1) == "0")
											{
												tmp03 = tmp01.mid(1,2);
												indice0 = tmp03.toInt( &ok, 10);
												pntdep = table_bombe[indice0];
												pntdep->setGeometry(posx+(96*depx),posy+(96*depy),48,48);
												plateau[herox + (depx*2)][heroy + (depy*2)] = plateau[herox + depx][heroy + depy];
												plateau[herox + depx][heroy + depy] = "0  ";
// *** Calculs de position et déplacement du héro ******************
												posx = posx + (48 * depx);
												posy = posy + (48 * depy);
												herox = herox + depx;
												heroy = heroy + depy;
												pntlab->setGeometry(posx,posy,48,48);
												ctrl_poissons();
											}
										}
										else
										{
											if (tmp01.mid(0,1) == "H")
											{
												tmp02 = plateau[herox + (depx*2)][heroy + (depy*2)];
												if (tmp02.mid(0,1) == "0" || tmp02.mid(0,1) == "C")
												{
													if(tmp02.mid(0,1) == "C")
													{
														tmp03 = tmp02.mid(1,2);
														indice0 = tmp03.toInt( &ok, 10);
														pntdep = table_cube[indice0];
														pntdep->hide();
													}
													tmp03 = tmp01.mid(1,2);
													indice0 = tmp03.toInt( &ok, 10);
													pntdep = table_hache[indice0];
													pntdep->setGeometry(posx+(96*depx),posy+(96*depy),48,48);
													plateau[herox + (depx*2)][heroy + (depy*2)] = plateau[herox + depx][heroy + depy];
													plateau[herox + depx][heroy + depy] = "0  ";
// *** Calculs de position et déplacement du héro ******************
													posx = posx + (48 * depx);
													posy = posy + (48 * depy);
													herox = herox + depx;
													heroy = heroy + depy;
													pntlab->setGeometry(posx,posy,48,48);
//
													tmp02 = plateau[(herox + depx)+1][(heroy + depy)];
													if(tmp02.mid(0,1) == "C")
													{
														tmp03 = tmp02.mid(1,2);
														indice0 = tmp03.toInt( &ok, 10);
														pntdep = table_cube[indice0];
														pntdep->hide();
														plateau[(herox + depx)+1][(heroy + depy)] = "0  ";
													}
//
													tmp02 = plateau[(herox + depx)-1][(heroy + depy)];
													if(tmp02.mid(0,1) == "C")
													{
														tmp03 = tmp02.mid(1,2);
														indice0 = tmp03.toInt( &ok, 10);
														pntdep = table_cube[indice0];
														pntdep->hide();
														plateau[(herox + depx)-1][(heroy + depy)] = "0  ";
													}
//
													tmp02 = plateau[(herox + depx)][(heroy + depy)+1];
													if(tmp02.mid(0,1) == "C")
													{
														tmp03 = tmp02.mid(1,2);
														indice0 = tmp03.toInt( &ok, 10);
														pntdep = table_cube[indice0];
														pntdep->hide();
														plateau[(herox + depx)][(heroy + depy)+1] = "0  ";
													}
//
													tmp02 = plateau[(herox + depx)][(heroy + depy)-1];
													if(tmp02.mid(0,1) == "C")
													{
														tmp03 = tmp02.mid(1,2);
														indice0 = tmp03.toInt( &ok, 10);
														pntdep = table_cube[indice0];
														pntdep->hide();
														plateau[(herox + depx)][(heroy + depy)-1] = "0  ";
													}
//
													ctrl_poissons();
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void mainfrm::cassetout()
{
// *** On casse tout ***********************************

// *** LE LOGO OK ***
	delete pntpok;

// *** LES MURS ***
	indice0 = 0;
	while (indice0 < cpt_mur)
	{
		delete table_mur[indice0];
		indice0 = indice0 + 1;
	}

// *** LA GLACE ***
	indice0 = 0;
	while (indice0 < cpt_glace)
	{
		delete table_glace[indice0];
		indice0 = indice0 + 1;
	}

// *** L'EAU ***
	indice0 = 0;
	while (indice0 < cpt_eau)
	{
		delete table_eau[indice0];
		indice0 = indice0 + 1;
	}

// *** LES COEURS ***
	indice0 = 0;
	while (indice0 < max_coeur)
	{
		delete table_coeur[indice0];
		indice0 = indice0 + 1;
	}

// *** LES BOMBES ***
	indice0 = 0;
	while (indice0 < cpt_bombe)
	{
		delete table_bombe[indice0];
		indice0 = indice0 + 1;
	}

// *** LES CAISSES ***
	indice0 = 0;
	while (indice0 < cpt_cube)
	{
		delete table_cube[indice0];
		indice0 = indice0 + 1;
	}

// *** LES CAISSES NEIGE ***
	indice0 = 0;
	while (indice0 < cpt_cube_neige)
	{
		delete table_cube_neige[indice0];
		indice0 = indice0 + 1;
	}

// *** LES CUBES MAGIQUES ***
	indice0 = 0;
	while (indice0 < cpt_cube_magique)
	{
		delete table_cube_magique[indice0];
		indice0 = indice0 + 1;
	}

// *** LES SURPRISES ***
	indice0 = 0;
	while (indice0 < cpt_surprise)
	{
		delete table_surprise[indice0];
		indice0 = indice0 + 1;
	}

// *** LES MONSTRES_1 ***
	indice0 = 0;
	while (indice0 < cpt_monstre_1)
	{
		delete table_monstre_1[indice0];
		indice0 = indice0 + 1;
	}

// *** LES MONSTRES_2 ***
	indice0 = 0;
	while (indice0 < cpt_monstre_2)
	{
		delete table_monstre_2[indice0];
		indice0 = indice0 + 1;
	}

// *** LES MONSTRES_3 ***
	indice0 = 0;
	while (indice0 < cpt_monstre_3)
	{
		delete table_monstre_3[indice0];
		indice0 = indice0 + 1;
	}

// *** LES MONSTRES_4 ***
	indice0 = 0;
	while (indice0 < cpt_monstre_4)
	{
		delete table_monstre_4[indice0];
		indice0 = indice0 + 1;
	}

// *** LES MONSTRES_5 ***
	indice0 = 0;
	while (indice0 < cpt_monstre_5)
	{
		delete table_monstre_5[indice0];
		indice0 = indice0 + 1;
	}

// *** LES HACHES ***
	indice0 = 0;
	while (indice0 < cpt_hache)
	{
		delete table_hache[indice0];
		indice0 = indice0 + 1;
	}

// *** LES BATEAUX ***
	indice0 = 0;
	while (indice0 < cpt_bateau_1)
	{
		delete table_bateau_1[indice0];
		indice0 = indice0 + 1;
	}

// *** LES AUTRES ***
	indice0 = 0;
	while (indice0 < cpt_autre)
	{
		delete table_autre[indice0];
		indice0 = indice0 + 1;
	}

// *** LE HERO ***
	delete pntlab;

// *** Chargement niveau ***
	charge_level();
}

void mainfrm::init()
{
// ***Création d'un timer ***
	mytimer = new QTimer( this );
        connect( mytimer, SIGNAL(timeout()), SLOT(move_ennemis()) );

	mytimer_2 = new QTimer( this );
        connect( mytimer_2, SIGNAL(timeout()), SLOT(move_ennemis_3()) );

	mytimer_3 = new QTimer( this );
        connect( mytimer_3, SIGNAL(timeout()), SLOT(move_ennemis_4()) );

	mytimer_4 = new QTimer( this );
        connect( mytimer_4, SIGNAL(timeout()), SLOT(move_bateaux_1()) );

	mytimer_5 = new QTimer( this );
        connect( mytimer_5, SIGNAL(timeout()), SLOT(move_ennemis_5()) );
// *** Création du fond d'écran ***
	mylab = new QLabel( this );
        QPixmap *mypix = new QPixmap("Images/fond.jpg");
        mylab->setPixmap( *mypix );
        mylab->setGeometry(0,0,856,668);
        mylab->show();

// *** Création du logo du bandeau latéral ***
	mylab = new QLabel( this );
        mypix->load("Images/tuxlogo.png");
        mylab->setPixmap( *mypix );
        mylab->setGeometry(890,280,111,125);
        mylab->show();

// *** Chargement de la progression dans le jeu ***
	QString myrec;
	QFile myfic("data.dat");
	if ( myfic.open( IO_ReadOnly ) )
	{
		QTextStream mystream (&myfic);
		myrec = mystream.readLine();
		progress = myrec;
		myfic.close();
	}
	else
	{
		if ( myfic.open( IO_WriteOnly ))
		{
			myfic.writeBlock("0000000000000000000000000000000000000000000000000",49);
			myfic.close();
			progress = "0000000000000000000000000000000000000000000000000";
		}
		else
		{
			QMessageBox::warning(this, "Anomalie", "Je n arrive pas a créer le fichier de progression ...");
		}
	}
// *** Chargement du premier niveau ***
	culevel = 0;
	charge_level();
}

void mainfrm::vidage()
{
// *** Vidage mémoire du plateau ***
	indice0=0;
	indice1=0;
	while (indice1 < 14)
	{
		while (indice0 < 18)
		{
			printf(plateau[indice0][indice1]);
			indice0=indice0 + 1;
		}
		printf("\n");
		indice1 = indice1 + 1;
		indice0 = 0;
	}
}

void mainfrm::nextlevel()
{
	if (culevel < 48)
	{
		culevel = culevel + 1;
		cassetout();
	}
	else
	{
		culevel = 0;
		cassetout();
	}

}


void mainfrm::prevlevel()
{
	if (culevel > 0)
	{
		culevel = culevel - 1;
		cassetout();
	}
	else
	{
		culevel = 48;
		cassetout();
	}
}


void mainfrm::restartlevel()
{
	cassetout();
}
