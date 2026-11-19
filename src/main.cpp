#include <sil/sil.hpp>
#include "random.hpp"
#include <random>
#include <cmath>

void keep_green_only(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    //Logo imac en vert
    for (glm::vec3& color : image.pixels())
    {
    color.r = 0.f;
    color.b= 0.f;
    }
}

void channels_swap(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    for (glm::vec3& color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
}

void noir_blanc(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    for (glm::vec3& color : image.pixels())
    {
        float grey = (color.r + color.g + color.b) / 3.0f;
        color = glm::vec3{grey, grey, grey};
    }
}

void negatif(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3{1.f} - color;
    }
}

void degrade(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    sil::Image degrade{300 /*width*/, 200 /*height*/};
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y) = glm::vec3{static_cast<float>(x) / static_cast<float>(image.width() - 1)};
        }
    }
}

void miroir(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width() / 2; ++x) {
            std::swap(image.pixel(x, y), image.pixel(image.width() - 1 - x, y));
        }
    }
}

void bruite(sil::Image& image)
{
    for (int y = 0; y < image.height(); ++y)
    {
        for (int x = 0; x < image.width(); ++x)
        {
            if (true_with_probability(0.1f))
            {
                image.pixel(x, y) = glm::vec3{
                    random_float(0.f, 1.f),
                    random_float(0.f, 1.f),
                    random_float(0.f, 1.f)
                };
            }
        }
    }
}

void rota(sil::Image& image)
{
    sil::Image tournee{image.height(), image.width()};

    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            tournee.pixel(image.height() - 1 - y, x) = image.pixel(x, y);
        }
    }

    image = tournee;
}

void rgbsplit(sil::Image& image)
{
    sil::Image split{image};

    for (int x = 50; x < image.width()-50; ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            split.pixel(x,y)= glm::vec3{image.pixel(x+50, y).r, image.pixel(x,y).g, image.pixel(x-50, y).b};
        }
    }
    image=split;

}

void lumi(sil::Image& image)
{
    //1er methode:
    // for (glm::vec3& color : image.pixels())
    // {
    // color.r = std::pow(color.r, 0.6f);
    // color.g = std::pow(color.g, 0.6f);
    // color.b = std::pow(color.g, 0.6f);
    // }

    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            image.pixel(x, y).r = std::pow(image.pixel(x, y).r, 0.1f);
            image.pixel(x, y).g = std::pow(image.pixel(x, y).g, 0.1f);
            image.pixel(x, y).b = std::pow(image.pixel(x, y).b, 0.1f);
        }
    }
}

void disque(sil::Image& image)
{
    sil::Image noir{500/*width*/, 500/*height*/};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            int rayon{100};
            int centreX{250};
            int centreY{250};
            int dx = x - centreX;
            int dy = y - centreY;

            if (dx*dx + dy*dy < rayon*rayon)
            {
                noir.pixel(x,y) = glm::vec3{1, 1, 1};
            }
            

        }
    }
    image = noir;

}

void cercle(sil::Image& image)
{
    sil::Image noir{500/*width*/, 500/*height*/};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            int thickness{10};
            int rayon{100};
            int centreX{250};
            int centreY{250};
            int dx = x - centreX;
            int dy = y - centreY;

            

            if (dx*dx + dy*dy < rayon*rayon)
            {
                noir.pixel(x,y) = glm::vec3{1, 1, 1};
            }

            if (dx*dx + dy*dy < thickness*thickness)
            {
                noir.pixel(x,y) = glm::vec3{0, 0, 0};
            }
            

        }
    }
    image = noir;
}

void animation(sil::Image& image)
{
    sil::Image noir{500/*width*/, 500/*height*/};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            int rayon{100};
            int centreX{500};
            int centreY{250};
            int dx = x - centreX;
            int dy = y - centreY;

            if (dx*dx + dy*dy < rayon*rayon)
            {
                noir.pixel(x,y) = glm::vec3{1, 1, 1};
            }
            

        }
    }
    image = noir;

}

void rosace(sil::Image image)
{
    sil::Image noir{500/*width*/, 500/*height*/};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            int thickness{10};
            int rayon{100};
            int centreX{250};
            int centreY{250};
            int dx = x - centreX;
            int dy = y - centreY;

            if (dx*dx + dy*dy < rayon*rayon)
            {
                noir.pixel(x,y) = glm::vec3{1, 1, 1};
            }

            if (dx*dx + dy*dy < thickness*thickness)
            {
                noir.pixel(x,y) = glm::vec3{0, 0, 0};
            }

        }
        for (int i = 0; i < 6; i++)
        {
            float angle = 2.f * 3.14159f * i / 6.f;
            
        }
        
    }
    image = noir;
}

void mosaique(sil::Image& image){
    sil::Image resultat{5 * image.width(), 5 * image.height()};
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            for (int row = 0; row < 5; row++)
            {
                for (int col = 0; col < 5; col++)
                {
                    resultat.pixel(image.width() * row + x, image.height() * col + y) = image.pixel(x,y);
                }
                
            }
            
        }

        
    }
    image=resultat;
}

void mosaiquemirr(sil::Image& image)
{
    sil::Image resultat{5 * image.width(), 5 * image.height()};
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
        
    
            for (int col = 0; col < 5; col++)
            {
                for (int row = 0; row < 5; row++){     
                    
                    if ((col - 1)%2 ==0){
                        resultat.pixel(x + row * image.width(), y + col * image.height()) = image.pixel(x, image.height()-1-y);
                    }
                    if ((row - 1)%2 ==0){
                        resultat.pixel(x + row * image.width(), y + col * image.height()) = image.pixel(image.width()-1-x, y);
                    }
                    
                    else{
                        resultat.pixel(x + row * image.width(), y + col * image.height()) = image.pixel(x, y);
                    }
                    
                }
            }
        
        }
    }
    image = resultat;  
}
void glitch(sil::Image& image)
{
    for (int y = 0; y < image.height(); ++y)
    {
        for (int x = 0; x < image.width(); ++x)
        {
            if (true_with_probability(0.005f))
            {
                
                int rect_width  = random_int(10, 50);
                int rect_height = random_int(2, 10);

                glm::vec3 random_color{
                    image.pixel(x,y)
                    
                };

                for (int dy = 0; dy < rect_height; ++dy)
                {
                    for (int dx = 0; dx < rect_width; ++dx)
                    {
                        int px = x + dx;
                        int py = y + dy;

                        if (px < image.width() && py < image.height())
                        {
                            image.pixel(px, py) = random_color;
                        }
                    }
                }
            }
        }
    }
}

void tri (sil::Image& image){

}

void degradecol(sil::Image& image) // Prend l'image par référence pour pouvoir la modifier
{
    glm::vec3 rouge{1.f, 0.f, 0.f};
    glm::vec3 vert{0.f, 1.f, 0.f};

    for (int x{0}; x < image.width(); ++x)
    {
        float t = image.width() > 1 ? static_cast<float>(x) / static_cast<float>(image.width() - 1)
            : 0.f;
        glm::vec3 couleur = glm::mix(rouge, vert, t);

        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y) = couleur;
        }
    }
}


int main()
{
    {
    sil::Image image{"images/logo.png"};
    keep_green_only(image);
    image.save("output/pouet.png");
    }

    {
    sil::Image image{"images/logo.png"};
    channels_swap(image);
    image.save("output/pouett.png");
    }

    {
    sil::Image image{"images/logo.png"};
    noir_blanc(image);
    image.save("output/n&b.png");
    }

    {
    sil::Image image{"images/logo.png"};
    negatif(image);
    image.save("output/negatif.png");
    }

    {
    sil::Image image{"images/logo.png"};
    degrade(image);
    image.save("output/degrade.png");
    }
    {
    sil::Image image{"images/logo.png"};
    miroir(image);
    image.save("output/miroir.png");
    }
    {
    sil::Image image{"images/logo.png"};
    bruite(image);
    image.save("output/bruite.png");
    }
    {
    sil::Image image{"images/logo.png"};
    rota(image);
    image.save("output/rotation.png");
    }
    {
    sil::Image image{"images/logo.png"};
    rgbsplit(image);
    image.save("output/rgbsplit.png");
    } 
    {
    sil::Image image{"images/photo.jpg"};
    lumi(image);
    image.save("output/lumi.png");
    }
    {
    sil::Image image{"images/photo.jpg"};
    disque(image);
    image.save("output/disque.png");
    } 
    {
    sil::Image image{"images/photo.jpg"};
    cercle(image);
    image.save("output/cercle.png");
    }
    {
    sil::Image image{"images/photo.jpg"};
    animation(image);
    image.save("output/animation.png");
    }
    {
    sil::Image image{"images/photo.jpg"};
    rosace(image);
    image.save("output/rosace.png");
    }
    {
    sil::Image image{"images/logo.png"};
    mosaique(image);
    image.save("output/mosaique.png");
    }
    {
    sil::Image image{"images/logo.png"};
    mosaiquemirr(image);
    image.save("output/mosaiquemirr.png");
    }
    {
    sil::Image image{"images/logo.png"};
    glitch(image);
    image.save("output/glitch.png");
    }
    {
    sil::Image image{"images/logo.png"};
    tri(image);
    image.save("output/tri.png");
    }
    {
    sil::Image image{"images/logo.png"};
    degradecol(image);
    image.save("output/degradecol.png");
    }
}