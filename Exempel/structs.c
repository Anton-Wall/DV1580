struct Vertex
{
    float x;
    float y;
    float z;
};

// struct Vertex
// {
//     float x, y, z;
// };

void func(struct Vertex vertices[])
{
    /* data */
}

int main(void)
{
    struct Vertex vertices[3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}};

    struct Vertex vertices1[3];
    vertices1[0] = (struct Vertex){1, 2, 3}; // we need to cast it.
    vertices1[0].x = 4;
    vertices1[1].y = 5;

    func(vertices1);

    int a = 1;

    return 0;
}