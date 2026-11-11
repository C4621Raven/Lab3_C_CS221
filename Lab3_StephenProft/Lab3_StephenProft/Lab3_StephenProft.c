#include <stdio.h>
#include <stdlib.h>

struct video_game
{
	char* name;
	int year_released;
	double price;
};

struct book
{
	char* title;
	char* author;
	int curPage;
	int totPage;
};

void halfOff(struct video_game* p_game)
{
	p_game->price = (*p_game).price / 2;
}

void print_book(struct book b)
{
	printf("Title: %s\nAuthor: %s\nCurrent page: %d\nTotal pages: %d\n\n",b.title,b.author,b.curPage,b.totPage);
}

struct book* make_book(char* title, char* author, int curPage, int totPage)
{
	struct book* p_dune = malloc(sizeof(struct book));
	p_dune->title = title;
	p_dune->author = author;
	p_dune->curPage = curPage;
	p_dune->totPage = totPage;
	return p_dune;
}

void turn_a_page(struct book *b)
{
	b->curPage += b->totPage > b->curPage;
}

int get_pages_remaining(struct book *b)
{
	return b->totPage - b->curPage;
}

void flip_pages(struct book *b, int pages)
{
	b->curPage = (b->curPage + pages) > b->totPage ? b->totPage : ((b->curPage+pages) < 0 ? 0 : (b->curPage+pages));
}

void start_over(struct book *b)
{
	b->curPage = 0;
}

int main(int argc, char* argv[])
{
	struct video_game gameStack;
	gameStack.name = "Armored Core VI Fires of Rubicon";
	gameStack.year_released = 2023;
	gameStack.price = 59.99;

	struct video_game *p_gameHeap = malloc(sizeof(struct video_game));
	(*p_gameHeap).name = "Bloodborne";
	(*p_gameHeap).year_released = 2015;
	(*p_gameHeap).price = 19.99;

	p_gameHeap->name = "Sekiro: Shadows Die Twice";
	p_gameHeap->year_released = 2019;
	p_gameHeap->price = 59.99;

	halfOff(p_gameHeap);

	printf("%f\n\n", (*p_gameHeap).price);
	
	free(p_gameHeap);

	struct book* p_dune = make_book("Dune", "Frank Herbert", 1, 412);

	struct book HOL;
	HOL.title = "House Of Leaves";
	HOL.author = "Mark Z. Danielewski";
	HOL.curPage = 1;
	HOL.totPage = 709;

	print_book(*p_dune);
	print_book(HOL);

	turn_a_page(p_dune);
	turn_a_page(&HOL);
	printf("Dune pages remaining: %d\n", get_pages_remaining(p_dune));
	printf("HOL pages remaining: %d\n\n", get_pages_remaining(&HOL));

	flip_pages(p_dune, 1000);
	flip_pages(&HOL, 1000);
	printf("Dune pages remaining: %d\n", get_pages_remaining(p_dune));
	printf("HOL pages remaining: %d\n\n", get_pages_remaining(&HOL));

	flip_pages(p_dune, -1000);
	flip_pages(&HOL, -1000);
	printf("Dune pages remaining: %d\n", get_pages_remaining(p_dune));
	printf("HOL pages remaining: %d\n\n", get_pages_remaining(&HOL));

	flip_pages(p_dune, 100);
	flip_pages(&HOL, 100);
	printf("Dune pages remaining: %d\n", get_pages_remaining(p_dune));
	printf("HOL pages remaining: %d\n\n", get_pages_remaining(&HOL));

	start_over(p_dune);
	start_over(&HOL);

	print_book(*p_dune);
	print_book(HOL);

	free(p_dune);
}